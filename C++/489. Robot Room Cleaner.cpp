/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string>visited;
        dfs(robot, 0, 0, visited);
    }
    
    // Robot always facing UP
    void dfs(Robot& R, int r, int c, unordered_set<string>& visited) {
        if (visited.count(tostr(r, c))) {
            return;
        }
        R.clean();
        visited.insert(tostr(r, c));
        
        // Go through each direction, robot ALWAYS ends with UP
        
        // Up
        if (R.move()) {
            dfs(R, r - 1, c, visited);
            R.turnLeft();
            R.turnLeft();
            R.move();
            R.turnLeft();
            R.turnLeft();
        }
        
        // Left
        R.turnLeft();
        if (R.move()) {
            R.turnRight();
            dfs(R, r, c - 1, visited);
            R.turnRight();
            R.move();
            R.turnLeft();
            R.turnLeft();
        } 
        R.turnRight();
        
        // Right
        R.turnRight();
        if (R.move()) {
            R.turnLeft();
            dfs(R, r, c + 1, visited);
            R.turnLeft();
            R.move();
            R.turnLeft();
            R.turnLeft();
        }
        R.turnLeft();
        
        // Down
        R.turnLeft();
        R.turnLeft();
        if (R.move()) {
            R.turnLeft();
            R.turnLeft();
            dfs(R, r + 1, c, visited);
            R.move();
            R.turnLeft();
            R.turnLeft();
        }
        R.turnLeft();
        R.turnLeft();
    }
    
    string tostr(int r, int c) {
        return to_string(r) + "," + to_string(c);
    }
};
