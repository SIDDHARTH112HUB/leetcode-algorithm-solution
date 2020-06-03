//Link: https://leetcode.com/problems/day-of-the-week/ 
/**
 * @param {number} day
 * @param {number} month
 * @param {number} year
 * @return {string}
 */
var dayOfTheWeek = function(day, month, year) {
    const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    const date = new Date(year + "-" + month +"-" + day);
    return days[date.getDay()];
};