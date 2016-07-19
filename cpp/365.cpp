class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0 || z == x + y) {
            return true;
        }

        if (z > x + y) {
            return false;
        }

        if (x == 0) {
            return z == y;
        }

        if (y == 0) {
            return z == x;
        }

        if (x == y) {
            return z == x;
        }

        int xIn = (y > x) ? x : y;
        int yIn = (y > x) ? y : x;

        int r = yIn % xIn;

        if (r == 0) {
            return z % xIn == 0;
        } else {
            return z % gcd(r, xIn) == 0;
        }
    }

private:
    int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        } else {
            return gcd(b, a % b);
        }
    }
};