class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int st, int et) {
        mp[st]++;
        mp[et]--;
        int count = 0;
        int maxCount = 0;
        for(auto &it:mp)
        {
            count+=it.second;
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */