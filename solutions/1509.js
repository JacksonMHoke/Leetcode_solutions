// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
var minDifference = function(nums) {
    if (nums.length<5)
        return 0;
    nums.sort((a,b)=>a-b);
    let min=Number.MAX_SAFE_INTEGER;
    for (let i=0; i<4; ++i)
        min=Math.min(min, nums.at(i-4)-nums[i]);
    return min;
};