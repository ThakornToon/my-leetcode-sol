impl Solution {
    pub fn filter_restaurants(restaurants: Vec<Vec<i32>>, vegan_friendly: i32, max_price: i32, max_distance: i32) -> Vec<i32> {
        let mut filtered: Vec<(i32, i32)> = restaurants
            .iter()
            .filter(|r| {
                if vegan_friendly == 1 && r[2] == 0 {
                    return false;
                }
                if r[3] > max_price {
                    return false;
                }
                if r[4] > max_distance {
                    return false;
                }
                true
            })
            .map(|r| (r[1], r[0]))  // (rating, id)
            .collect();
        
        // เรียงลำดับ: rating desc, id desc
        filtered.sort_by(|a, b| {
            if a.0 != b.0 {
                b.0.cmp(&a.0)  // rating desc
            } else {
                b.1.cmp(&a.1)  // id desc
            }
        });
        
        filtered.into_iter().map(|(_, id)| id).collect()
    }
}