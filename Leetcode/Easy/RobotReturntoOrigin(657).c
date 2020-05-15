/*
 * There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), L (left), U (up), and D (down). If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.

Note: The way that the robot is "facing" is irrelevant. "R" will always make the robot move to the right once, "L" will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.
 */
bool judgeCircle(char * moves){
    int dis_v=0;
    int dis_h=0;
    for(int i=0;i<strlen(moves);i++)
    {
        if(moves[i]=='U')
                dis_v++;
        else if(moves[i]=='D')
                dis_v--;
        else if(moves[i]=='R')
                dis_h++;
        else if(moves[i]=='L')
                dis_h--;
    }

    if(dis_v==0 && dis_h==0) return true;
    else return false;
}
