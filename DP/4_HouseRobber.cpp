// Maximum money of Non-Adjacent houses BUT Houses are in form of a circle.

// Approach: Same as previous But last & first house are neighbours

// Take 2 arrays: First & Last
// First includes elements from 0 to n-2
// Last includes elements from 1 to n-1
// return max(solve(first),solve(second));