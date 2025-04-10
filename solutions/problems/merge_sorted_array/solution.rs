impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut id:usize = 0;
        let mut count:i32 = 0;
        for i in nums2{
            while (id as i32) < m+n{
                if nums1[id]==0 && *i>=nums1.iter().max().map(|&x|x).unwrap_or_default() && (id as i32) >= m+count{
                    nums1[id]=*i;
                    count+=1;
                    id+=1;
                    break;
                }
                else if *i<nums1[id]{
                    for c in (id..((m+n) as usize)).rev(){
                        if c!=0 {
                            nums1[c]=nums1[c-1];
                        }
                    }
                    nums1[id]=*i;
                    count+=1;
                    id+=1;
                    break;
                }
                id+=1;
            }
        }
    }
}