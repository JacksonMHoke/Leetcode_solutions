// 1598. Crawler Log Folder
/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let level=0;
    logs.forEach((log) => {
        if (log=="../")
            level=Math.max(level-1, 0);
        else if (log!="./")
            level+=1;
    });
    return level;
};