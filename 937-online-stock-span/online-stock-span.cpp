class StockSpanner {
private:
    void clear(stack<pair<int,int>>& st){
        while(!st.empty()){
            st.pop();
        }
    }
public:
    int ind=-1;
    stack<pair<int,int>> st;

    StockSpanner() {
        //StockSpanner is a function which is called for every test case(and not for every next function) to make sure ind==-1 && stack is empty for next test case
        ind=-1;
        clear(st);
    }
    
    int next(int price) {
        ind = ind + 1; //incrementing it for every next function called

        //the stack here used kinda gives previous greater price for current price
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        //then the index of that previous greater price(w.r.t current price) is directly used to calculate the span for that particular price
        //by subtraction of the index of current price and index of that previous greater price
        int ans = ind - (st.empty() ? -1 : st.top().second);

        st.push({price,ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */