// 1380. Lucky Numbers in a Matrix
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers  = function(matrix) {
    rt = [];
    maxCol=Array(matrix[0].length).fill(-1);
    minRow=Array(matrix.length).fill(1e7);
    for (let i=0; i<matrix.length; ++i) {
        for (let j=0; j<matrix[i].length; ++j) {
            maxCol[j]=Math.max(maxCol[j], matrix[i][j]);
            minRow[i]=Math.min(minRow[i], matrix[i][j]);
        }
    }

    for (let i=0; i<matrix.length; ++i) {
        for (let j=0; j<matrix[i].length; ++j) {
            if (matrix[i][j]==minRow[i] && matrix[i][j]==maxCol[j]) {
                rt.push(matrix[i][j]);
            }
        }
    }

    return rt;
};