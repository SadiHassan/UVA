#include<bits/stdc++.h>
using namespace std;

/*
Note that two anagram strings are equal when sorted.
Note also that each sequence of "push" and "pop" operations for a string of length n
is composed of balanced arrangement of n "push" operations and n "pop" operation
such that no "pop" operation is done when the stack is empty.

In other words, the only valid operation when the stack is empty is "push".
It also follows that the first operation in any valid sequence is "push",
and that the last operation in any valid sequence is "pop".

Finally, note that "pop" is valid only if the letter on top of the stack is equal
to the next letter in the target string.

It follows from these constraints that it is not necessary to generate
all possible 2n! full permutations of n "push" and n "pop" operations,
and that a candidate prefix of the possible sequence can be pruned as soon as
it is invalid with respect to target string and with respect to the present state
of stack regardless of any used postfix.

We do not have to use a map to keep track of the frequency of each letter. But if we do, both maps for the source word and the destination word have to be equal. Let us assume that both words are anagram, i.e. they have the same number of letters n and the same frequency for each existing letter. Let us assume that we have two pointer i and o that denote the position in the source word and destination word to be pushed to the stack and to be popped from the stack, respectively. Initially, i=o=0 and the stack is empty. There are two different cases. The first case is when i<n, the present letter src[i] can be pushed to the stack, and i is incremented. The second case is when o<n, the stack is not empty and dest[o] is equal to the top of the stack, then top of the stack can be popped from the stack, and o is incremented. The final state is reached when i=o=n. This is a decision tree in which each "push" or "pop" choice is an edge in the tree, and non-leaf nodes have one or two children nodes, and the leaf nodes where the final state is reached represent a valid sequence. Each valid sequence is this tree is a path from the root node to a leaf node where the edges are marked with either "push" or "pop".
https://codeforces.com/blog/entry/80816
*/

template <class Container, class Stream>
Stream& printOneValueContainer
    (Stream& outputstream, const Container& container)
{
    typename Container::const_iterator beg = container.begin();

    outputstream << "[";

    while(beg != container.end())
    {
        outputstream << " " << *beg++;
    }

    outputstream << " ]";

    return outputstream;
}

template < class Type, class Container >
const Container& container
    (const std::stack<Type, Container>& stack)
{
    struct HackedStack : private std::stack<Type, Container>
    {
        static const Container& container
            (const std::stack<Type, Container>& stack)
        {
            return stack.*&HackedStack::c;
        }
    };

    return HackedStack::container(stack);
}

template < class Type, class Container >
const Container& container
    (const std::queue<Type, Container>& queue)
{
    struct HackedQueue : private std::queue<Type, Container>
    {
        static const Container& container
            (const std::queue<Type, Container>& queue)
        {
            return queue.*&HackedQueue::c;
        }
    };

    return HackedQueue::container(queue);
}

template
    < class Type
    , template <class Type, class Container = std::deque<Type> > class Adapter
    , class Stream
    >
Stream& operator<<
    (Stream& outputstream, const Adapter<Type>& adapter)
{
    return printOneValueContainer(outputstream, container(adapter));
}

bool check(string str, string ans){
    int len = str.size();
    /*
    while(!st.empty()){
        if(str[ind] != st.top()) return false;
        ind--;
        st.pop();
    }
    */
    for(int i = 0; i < len; i++)
        if(str[i] != ans[i]) return false;
    return true;
}

int rec(string str1, string str2, stack<char>& st, vector<string>& arr, string sequence, int ind, string ans, int target_ind){
    //cout << st << endl;
    //cout << ans << endl;
    int len = str1.size();
    //cout << len << " " << ans.size() << " " << ind << endl;
    if(ans.size() >= len){
        if(check(str2, ans)){
            arr.push_back(sequence);
            cout << ans << endl;
        }
        return 0;
    }
    //cout << str2[target_ind] << endl;
    //cout << "-------" << endl;
    if(!st.empty()){
        if(st.top() == str2[target_ind]){
            ans += st.top();
            char ch = st.top();
            cout << "o: " << st.top() << endl;
            st.pop();
            rec(str1, str2, st, arr, sequence + "o", ind, ans, target_ind + 1);
            //ind -= 1;
            st.push(ch);
        }
    }
    if(ind < len){
        cout << "i: " << str1[ind] << endl;
        st.push(str1[ind]);
        rec(str1, str2, st, arr, sequence + "i", ind + 1, ans, target_ind);
    }

    //st.pop();



    return 0;
}

int main(){

string str1, str2;

while(cin >> str1){
    cin >> str2;
    if(str1.size() != str2.size()){
        cout << "[" << endl;
        cout << "]" << endl;
        continue;
    }
    vector<string> arr;
    stack<char> st;
    rec(str1, str2, st, arr, "", 0, "", 0);
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
return 0;
}
