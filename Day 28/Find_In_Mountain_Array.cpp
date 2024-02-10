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
    int b_Search(int target, MountainArray &mountainArr, int s, int e){
        int mid = e+(s-e)/2;
        while(s<=e){
            if(mountainArr.get(mid)>target) e = mid-1;
            else if(mountainArr.get(mid)<target) s = mid+1;
            else return mid;
            mid = e+(s-e)/2;
        }
        return -1;
    }
    int b_SearchRev(int target, MountainArray &mountainArr, int s, int e){
        int mid = e+(s-e)/2;
        while(s<=e){
            if(mountainArr.get(mid)>target) s = mid+1;
            else if(mountainArr.get(mid)<target) e = mid-1;
            else return mid;
            mid = e+(s-e)/2;
        }
        return -1;
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int s= 0, e = len-1;
        int mid = s+(e-s)/2;
        int ans = -1;

        while(s<e){
            //cout<<s<<" "<<e<<"   "<<mid<<endl;
            mid=s+(e-s)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }


        cout<<mid<<endl;
        //now find in two ranges
        int a = b_Search(target, mountainArr, 0, mid);
        if(a!=-1) return a;
        int b  = -1;
        if(mid+1<len)
            b = b_SearchRev(target, mountainArr, mid+1, len-1);
        return b;
    }
};
