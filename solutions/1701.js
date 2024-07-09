// 1701. Average Waiting Time
/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(customers) {
    let time=0;
    let totWaitingTime=0;
    for (let i=0; i<customers.length; ++i) {
        time=Math.max(time, customers[i][0])+customers[i][1];
        totWaitingTime+=time-customers[i][0];
    }
    return totWaitingTime/customers.length;
};