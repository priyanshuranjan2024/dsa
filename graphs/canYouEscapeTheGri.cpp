//ques
//given a grid of nxm size.every cell of the grid, are marked as "l",'r','u','d'.characters on a cell denotes if you are
//standing atthat cell.what direction you can move to .check if we start from (0,0) can we reach (n-1,m-1)?
//space complexity O(1)


//basically if there exists a cycle then we can't escape the matrix

//approach 1
// there won't be a cycle if there is a escape.
// we will get a cycle if we visit a cell twice
// so we can use a step counter in worst case we will need nxm steps maximum to reach the destination
// if we don't reach the dest and step>nxm then there is a cycle and we will return false
// apply by using a while loop

//approach 2(main)
// where ever you see a cycle detection question use hare and tortoise principle as it very optimized
// if hare and tortoise don't meet and hare escapes then this will mean that return true and if you get outside the grid then also you can't escape the grid


