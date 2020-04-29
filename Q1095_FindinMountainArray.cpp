/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int t;
    int finda(MountainArray &mountainArr, int l, int r) {
        while (l <= r) {
            int mid = l + r >> 1;
            int val = mountainArr.get(mid);
            if (val == t) return mid;
            else if (val < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }

    int findd(MountainArray &mountainArr, int l, int r) {
        while (l <= r) {
            int mid = l + r >> 1;
            int val = mountainArr.get(mid);
            if (val == t) return mid;
            else if (val < t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int l = 0, r = len-1;
        int res = -1;
        int rres = -1;

        t = target;

        while (l <= r && l >= 0 && r < len) {
            int mid = l + r >> 1;
            if (l == r) {
                if (mountainArr.get(l) == target) return l;
                break;
            }
            if (mid == l) {
                if (mountainArr.get(l) == target) return l;
                if (mountainArr.get(r) == target) return r;
                break;
            } 
            int a = mountainArr.get(mid-1);
            int b = mountainArr.get(mid);
            int c = mountainArr.get(mid+1);
            if (a < b && b < c) {
                if (c < target) {
                    l = mid + 2;
                    continue;
                }
                res = finda(mountainArr, l, mid+1);
                if (res != -1) return res;
                l = mid + 2;
            } else if (a > b && b > c) {
                if (a < target) {
                    r = mid - 2;
                    continue;
                }
                rres = findd(mountainArr, mid-1, r);
                r = mid - 2;
            } else {
                if (b < target) return -1;
                if (b == target) return mid;
                res = finda(mountainArr, l, mid-1);
                if (res != -1) return res;
                if (rres != -1) return rres;
                rres = findd(mountainArr, mid+1, r);
                break;
            }
        }
        return rres;    
    }
};