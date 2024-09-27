
// Problem Link : https://leetcode.com/problems/my-calendar-ii/description/

class MyCalendarTwo {
public:
    set<pair<int,int>>booking;
    set<pair<int,int>>dBook;
    
    MyCalendarTwo() {
        
    }
    // check krega overlap region ko
    bool checkOverlap(int start1, int end1, int start2,int end2){
        return max(start1,start2) < min(end1, end2);
    }

    // ye overlapp region return krega
    pair<int, int> findRegion(int start1, int end1, int start2, int end2){
        return {max(start1,start2), min(end1, end2)};
    }

    bool book(int start, int end) {
        // checked ki triple booking to nhi ho rha
       for(auto it : dBook){
        if(checkOverlap(it.first, it.second, start, end)){
            return false;
        }
       }

       // now, find overlapped region and push it in set
       for(auto it : booking){
          if(checkOverlap(it.first, it.second, start, end)){
            dBook.insert(findRegion(it.first, it.second, start,end));
          }
       }

       booking.insert({start,end});
       return true;


    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */