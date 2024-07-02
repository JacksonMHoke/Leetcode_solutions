// 350. Intersection of Two Arrays II
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    if (nums2.length<nums1.length)
        [nums1, nums2]=[nums2, nums1];

    let hashMap = new Map();
    for (let i=0; i<nums2.length; ++i) {
        if (!(nums2[i] in hashMap))
            hashMap[nums2[i]]=0;
        hashMap[nums2[i]]++;
    }

    let rt = [];
    for (let i=0; i<nums1.length; ++i) {
        if (hashMap[nums1[i]]>0) {
            rt.push(nums1[i]);
            hashMap[nums1[i]]--;
        }
    }
    return rt;
};