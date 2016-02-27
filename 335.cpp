class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int len = x.size(), i;
        if(len<=3) 
            return false;
            
        bool grow_spiral;

        for(i=3, grow_spiral = x[2] > x[0]; i < len;++i)
        {
            if(!grow_spiral && x[i] >= x[i-2]) 
                return true;//if it is a "shrink" case before x[i] and cross happens
                
            if(grow_spiral && x[i]<=x[i-2])
            { // if it is a grow case, and x[i] changes it to shrink
                    grow_spiral = false;
                    x[i-1] = x[i] + (i>=4?x[i-4]:0)<x[i-2]? x[i-1]:x[i-1]-x[i-3];// update boundary
            }
        }
        return false;
    }
};