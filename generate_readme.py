import os
import re
import urllib.parse
import requests

# กำหนด Path ของโฟลเดอร์โจทย์
solutions_path = "solutions/problems"
if not os.path.exists(solutions_path):
    solutions_path = "solutions"

folders = [d for d in os.listdir(solutions_path) if os.path.isdir(os.path.join(solutions_path, d))]

print(f"พบโฟลเดอร์โจทย์ทั้งหมด {len(folders)} ข้อ กำลังดึงข้อมูลโจทย์...")

tags_dataset_url = "https://raw.githubusercontent.com/WilliamZhang20/leetcode-clusters/master/data/problems.json"
try:
    response = requests.get(tags_dataset_url, timeout=15)
    response.raise_for_status()
    data = response.json()
except (requests.RequestException, ValueError) as e:
    raise SystemExit(f"ข้อผิดพลาด: ไม่สามารถดึงข้อมูลโจทย์ได้ ({e})") from e

if not isinstance(data, dict) or not isinstance(data.get("problems"), list):
    raise SystemExit("ข้อผิดพลาด: รูปแบบข้อมูลโจทย์ที่ได้รับไม่ถูกต้อง")

def normalize_key(s):
    return re.sub(r'[^a-z0-9]', '', s.lower())

# สร้าง Map ของข้อมูลโจทย์และ Topics / Tags
print("กำลังจัดเตรียมข้อมูล Topics / Tags...")
tags_map = {}
tag_name_lookup = {t["slug"]: t["name"] for t in data.get("tags", [])}

# สร้าง Map จับคู่ด้วย title_slug และ title
problem_map = {}
for p in data["problems"]:
    title_slug = p["slug"]
    question_id = int(p["id"])
    title = p["title"].strip()
    p_tags = [tag_name_lookup.get(t, t.title()) for t in p.get("tags", [])]

    item = {
        "id": question_id,
        "title": title,
        "difficulty": p["difficulty"],
        "slug": title_slug
    }
    problem_map[title_slug] = item
    problem_map[normalize_key(title_slug)] = item
    problem_map[normalize_key(title)] = item
    tags_map[title_slug] = p_tags
    tags_map[normalize_key(title_slug)] = p_tags
    tags_map[normalize_key(title)] = p_tags

# รวบรวมข้อมูลโจทย์ พร้อมแมตช์เลขข้อและ Topics
solved_problems = []

for folder in folders:
    slug = folder.replace("_", "-").lower()
    norm_key = normalize_key(folder)
    info = problem_map.get(slug) or problem_map.get(norm_key)
    
    folder_encoded = urllib.parse.quote(folder)
    link = f"[Code](./{solutions_path}/{folder_encoded})"
    
    # ค้นหา Tags ของโจทย์
    tags = tags_map.get(slug) or tags_map.get(norm_key)
    tags = tags or []
    
    if info:
        solved_problems.append({
            "id": info["id"],
            "title": info["title"],
            "difficulty": info["difficulty"],
            "tags": tags,
            "link": link
        })
    else:
        solved_problems.append({
            "id": 9999,
            "title": folder,
            "difficulty": "-",
            "tags": tags,
            "link": link
        })

# เรียงลำดับตามหมายเลขข้อ (ID) จากน้อยไปมาก
solved_problems = sorted(solved_problems, key=lambda x: x["id"])

def generate_markdown_table(problem_list, include_difficulty=True):
    if include_difficulty:
        header = "| No | Name | Difficulty | Topics | Code Link |\n| :---: | :--- | :---: | :--- | :---: |\n"
        rows = []
        for p in problem_list:
            qid = p["id"] if p["id"] != 9999 else "-"
            tags_formatted = ", ".join([f"`{t}`" for t in p["tags"]]) if p["tags"] else "-"
            rows.append(f"| {qid} | {p['title']} | {p['difficulty']} | {tags_formatted} | {p['link']} |")
    else:
        header = "| No | Name | Topics | Code Link |\n| :---: | :--- | :--- | :---: |\n"
        rows = []
        for p in problem_list:
            qid = p["id"] if p["id"] != 9999 else "-"
            tags_formatted = ", ".join([f"`{t}`" for t in p["tags"]]) if p["tags"] else "-"
            rows.append(f"| {qid} | {p['title']} | {tags_formatted} | {p['link']} |")
    return header + "\n".join(rows) + "\n"

easy_problems = [p for p in solved_problems if p["difficulty"] == "Easy"]
medium_problems = [p for p in solved_problems if p["difficulty"] == "Medium"]
hard_problems = [p for p in solved_problems if p["difficulty"] == "Hard"]

# จัดกลุ่มโจทย์ตาม Topic
topic_to_problems = {}
for p in solved_problems:
    for t in p.get("tags", []):
        if t not in topic_to_problems:
            topic_to_problems[t] = []
        topic_to_problems[t].append(p)

sorted_topics = sorted(topic_to_problems.keys(), key=lambda t: (-len(topic_to_problems[t]), t))

def to_anchor(text):
    s = text.lower().replace(" ", "-")
    return re.sub(r'[^a-z0-9\-_]', '', s)

# ----------------- สร้างเนื้อหา README.md -----------------
markdown_content = "# LeetCode Solutions\n\n"

# สารบัญนำทางข้ามแต่ละส่วน (Quick Section Navigation)
markdown_content += '<a id="contents"></a>\n'
markdown_content += "## 📌 Contents\n\n"
markdown_content += "- [📖 My LeetCode Journey](#my-leetcode-journey)\n"
markdown_content += "- [📂 Browse Problems by Category](#browse-problems)\n"
markdown_content += f"- [📋 All Solved Problems ({len(folders)} Problems)](#all-solved-problems)\n"
markdown_content += "- [⚙️ How to Set This Up Yourself](#how-to-set-this-up-yourself)\n\n"
markdown_content += "---\n\n"

# ส่วนที่ 1: ประวัติความเป็นมา
markdown_content += '### <a id="my-leetcode-journey"></a>📖 My LeetCode Journey\n\n'
markdown_content += "- **April 8, 2025:** Started solving LeetCode problems as a new hobby during the school break.\n"
markdown_content += "- **End of 2025:** Reached a net total of 643 solved problems.\n"
markdown_content += "- **May 21, 2026:** Successfully crossed the milestone of 1,000 solved problems!\n"
markdown_content += "- **Purpose:** This repository serves as a personal archive to store and showcase all the coding solutions I've submitted.\n\n"
markdown_content += "[⬆️ Back to Contents](#contents)\n\n"
markdown_content += "---\n\n"

# ส่วนที่ 2: สถิติแยกตามหมวดหมู่ (พร้อมลิงก์ไปยังไฟล์แยก)
markdown_content += '### <a id="browse-problems"></a>📂 Browse Problems\n\n'
markdown_content += f"- 🟢 **[Easy Problems ({len(easy_problems)})](./EASY.md)**\n"
markdown_content += f"- 🟡 **[Medium Problems ({len(medium_problems)})](./MEDIUM.md)**\n"
markdown_content += f"- 🔴 **[Hard Problems ({len(hard_problems)})](./HARD.md)**\n"
markdown_content += f"- 📚 **[Problems by Topics ({len(sorted_topics)} Topics)](./TOPICS.md)**\n\n"
markdown_content += "[⬆️ Back to Contents](#contents)\n\n"
markdown_content += "---\n\n"

# ส่วนที่ 3: สถิติและตารางสารบัญรวม
markdown_content += f'### <a id="all-solved-problems"></a>📋 All Solved Problems ({len(folders)} Problems)\n\n'
markdown_content += generate_markdown_table(solved_problems, include_difficulty=True)
markdown_content += "\n[⬆️ Back to Contents](#contents)\n\n"

# ส่วนที่ 4: คู่มือสำหรับคนที่อยากทำตาม
markdown_content += "----\n\n"
markdown_content += '### <a id="how-to-set-this-up-yourself"></a>⚙️ How to Set This Up Yourself\n\n'
markdown_content += "If you want to sync your LeetCode submissions to GitHub and generate an organized README like this, follow these steps:\n\n"
markdown_content += "### 1. Automated Sync via GitHub Actions\n"
markdown_content += "1. Create a new GitHub repository (e.g., `leetcode-solutions`).\n"
markdown_content += "2. Get your LeetCode session cookies (`LEETCODE_SESSION` and `csrftoken`) from your browser's Developer Tools (`F12` -> Application -> Cookies -> `leetcode.com`).\n"
markdown_content += "3. In your GitHub repository, go to **Settings** -> **Secrets and variables** -> **Actions**, and add two repository secrets:\n"
markdown_content += "   - `LEETCODE_SESSION`\n"
markdown_content += "   - `CSRFTOKEN`\n"
markdown_content += "4. Create a GitHub Action workflow file at `.github/workflows/leetcode.yml` with the following configuration:\n\n"
markdown_content += "```yaml\n"
markdown_content += "name: Sync LeetCode\n\n"
markdown_content += "on:\n"
markdown_content += "  workflow_dispatch:\n"
markdown_content += "  schedule:\n"
markdown_content += "    - cron: \"0 0 * * *\"\n\n"
markdown_content += "jobs:\n"
markdown_content += "  build:\n"
markdown_content += "    runs-on: ubuntu-latest\n"
markdown_content += "    permissions:\n"
markdown_content += "      contents: write\n"
markdown_content += "    steps:\n"
markdown_content += "      - uses: actions/checkout@v4\n"
markdown_content += "      - uses: actions/setup-python@v5\n"
markdown_content += "        with:\n"
markdown_content += "          python-version: \"3.x\"\n"
markdown_content += "      - run: python -m pip install requests\n"
markdown_content += "      - uses: ThakornToon/leetcode-sync@master   # you can select a different repository if needed\n"
markdown_content += "        with:\n"
markdown_content += "          github-token: ${{ secrets.GITHUB_TOKEN }}\n"
markdown_content += "          leetcode-session: ${{ secrets.LEETCODE_SESSION }}\n"
markdown_content += "          leetcode-csrf-token: ${{ secrets.CSRFTOKEN }}\n"
markdown_content += "          destination-folder: \"solutions\"\n"
markdown_content += "      - run: python generate_readme.py\n"
markdown_content += "      - name: Commit and push generated README files\n"
markdown_content += "        run: |\n"
markdown_content += "          git config user.name \"github-actions[bot]\"\n"
markdown_content += "          git config user.email \"41898282+github-actions[bot]@users.noreply.github.com\"\n"
markdown_content += "          git add README.md EASY.md MEDIUM.md HARD.md TOPICS.md\n"
markdown_content += "          if ! git diff --cached --quiet; then\n"
markdown_content += "            git commit -m \"Update generated LeetCode README files\"\n"
markdown_content += "            git push\n"
markdown_content += "          else\n"
markdown_content += "            echo \"No generated README changes to commit.\"\n"
markdown_content += "          fi\n"
markdown_content += "```\n\n"
markdown_content += "I initially used [`joshcai/leetcode-sync@v1.5`](https://github.com/joshcai/leetcode-sync) because I liked how it organized solution files and handled commits. I later ran into LeetCode API requests being blocked by Cloudflare, so I adapted the v1.5 code. You can find my adapted version at [`ThakornToon/leetcode-sync`](https://github.com/ThakornToon/leetcode-sync).\n\n"
markdown_content += "This Cloudflare issue is resolved in `leetcode-sync` v1.6 and later, but you will need to update `generate_readme.py` to work with those versions. I recommend using the latest version because it fixes fetching submissions for Premium problems. Some smaller improvements are still waiting for their pull requests to be merged. If you want to customize the project to your preferences, you can fork [`joshcai/leetcode-sync`](https://github.com/joshcai/leetcode-sync).\n\n"
markdown_content += "### 2. Generate README.md Automatically\n"
markdown_content += "You can use a Python script to scan your solution folders, fetch problem details (ID, title, difficulty) and topics from a public metadata dataset, sort them, and update your `README.md` automatically.\n\n"
markdown_content += "[⬆️ Back to Contents](#contents)\n\n"

# บันทึกไฟล์ README.md
with open("README.md", "w", encoding="utf-8") as f:
    f.write(markdown_content)

# บันทึกไฟล์ EASY.md
easy_content = f"# 🟢 LeetCode Easy Problems ({len(easy_problems)})\n\n"
easy_content += "[⬅️ Back to All Problems](./README.md) | [Problems by Topics 📚](./TOPICS.md) | [Medium Problems 🟡](./MEDIUM.md) | [Hard Problems 🔴](./HARD.md)\n\n"
easy_content += generate_markdown_table(easy_problems, include_difficulty=False)
with open("EASY.md", "w", encoding="utf-8") as f:
    f.write(easy_content)

# บันทึกไฟล์ MEDIUM.md
medium_content = f"# 🟡 LeetCode Medium Problems ({len(medium_problems)})\n\n"
medium_content += "[Easy Problems 🟢](./EASY.md) | [⬅️ Back to All Problems](./README.md) | [Problems by Topics 📚](./TOPICS.md) | [Hard Problems 🔴](./HARD.md)\n\n"
medium_content += generate_markdown_table(medium_problems, include_difficulty=False)
with open("MEDIUM.md", "w", encoding="utf-8") as f:
    f.write(medium_content)

# บันทึกไฟล์ HARD.md
hard_content = f"# 🔴 LeetCode Hard Problems ({len(hard_problems)})\n\n"
hard_content += "[Easy Problems 🟢](./EASY.md) | [Medium Problems 🟡](./MEDIUM.md) | [Problems by Topics 📚](./TOPICS.md) | [⬅️ Back to All Problems](./README.md)\n\n"
hard_content += generate_markdown_table(hard_problems, include_difficulty=False)
with open("HARD.md", "w", encoding="utf-8") as f:
    f.write(hard_content)

# บันทึกไฟล์ TOPICS.md
topics_content = f"# 📚 LeetCode Problems by Topics ({len(sorted_topics)} Topics)\n\n"
topics_content += "[⬅️ Back to All Problems](./README.md) | [Easy Problems 🟢](./EASY.md) | [Medium Problems 🟡](./MEDIUM.md) | [Hard Problems 🔴](./HARD.md)\n\n"
topics_content += "## Quick Navigation\n\n"
topics_content += "> Click on any topic to jump to its problem list.\n\n"

nav_links = [f"[`{t}` ({len(topic_to_problems[t])})](#{to_anchor(t)})" for t in sorted_topics]
topics_content += " · ".join(nav_links) + "\n\n"
topics_content += "---\n\n"

for t in sorted_topics:
    t_probs = sorted(topic_to_problems[t], key=lambda x: x["id"])
    anchor = to_anchor(t)
    topics_content += f'### <a id="{anchor}"></a>{t} ({len(t_probs)})\n\n'
    topics_content += "<details>\n"
    topics_content += f"<summary><b>View {len(t_probs)} problems</b></summary>\n\n"
    topics_content += "| No | Name | Difficulty | Code Link |\n"
    topics_content += "| :---: | :--- | :---: | :---: |\n"
    for p in t_probs:
        qid = p["id"] if p["id"] != 9999 else "-"
        topics_content += f"| {qid} | {p['title']} | {p['difficulty']} | {p['link']} |\n"
    topics_content += "\n[⬆️ Back to Top](#quick-navigation)\n\n"
    topics_content += "</details>\n\n"

with open("TOPICS.md", "w", encoding="utf-8") as f:
    f.write(topics_content)

print(f"สร้างไฟล์ README.md, EASY.md ({len(easy_problems)}), MEDIUM.md ({len(medium_problems)}), HARD.md ({len(hard_problems)}), TOPICS.md ({len(sorted_topics)} topics) สำเร็จ!")