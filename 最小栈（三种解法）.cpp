//最小栈解法一:(辅助栈和最小栈同步)
class MinStack{
	stack<int>dataStack;
	stack<int>minSatck;
puvlic :
	MinStack() {
		minStack.push(INT_MAX);
	}
	
	void push(int val) {
		dataStack.push(val);
		minStack.push( min (val , minStack.top() ) );
	}

	void pop() {
		dataStack.pop();
		minStack.pop();
	}

	int top() {
		return dataStack.top();
	}

	int getMin() {
		return minStack.top();
	}
};

解法二：辅助栈和最小栈不同步
class MinStack {
stack<int>dataStack;
stack<int>minStack;
public:
	MinStack() {

	}

	void push(int val) {
		dataStack.push(val);
		
		if ( minStack.empty() || val <= minStack.top() )  {//这里一定要注意等号的含义
				minStack.push(val);
		}
	}

	void pop() {
		if (minStack.top() == dataStack.top() ) {
			minStack.pop();
			dataStack.pop();
		}
		else {
			dataStack.pop();
		}
	}

	int top() {
		return dataStack.top();
	}

	int getMin() {
		return minStack.top();
	}
};
解法三:不会额外开辟辅助栈，让原始栈中保持差值即可，这样可使空间复杂度为O(1)
class MinStack {
    stack<long long >stack;
public:
    long long  min;
    MinStack() {

    }
    
    void push(int val) {
        if (stack.empty() ) {
            stack.push(0);
            min = val;
        }
        else {
            stack.push(val - min);
            if (val < min ) {
                min = val;
            }
        }
    }
    
    void pop() {
        if(stack.top() < 0 ) {
            min = min - stack.top();//要注意顺序，是先出栈还是先做差
            stack.pop();
        }
        else {
            stack.pop();
        }
    }
    
    int top() {
        if (stack.top() < 0 ) {
            return min;
        }
        else {
            return min+stack.top();
        }
    }
    
    int getMin() {
        return min;
    }
};
