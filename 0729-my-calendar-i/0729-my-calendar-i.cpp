class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>>b;
    bool book(int start, int end) {
        for(auto x:b){
            if(start<x.second && end>x.first){
                return false;
            }
        }
        b.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */