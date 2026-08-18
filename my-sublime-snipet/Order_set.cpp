
/*****************************     If need same type single element     **********************************/
/****************************              1 2 3 4 5 6 7 8 9           **********************************/


#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/**

oset<int>se;                    [declear a set]
se.insert(val);                 [insert a value]             [ O(log(n)) ]
cout << se.order_of_key(val);   [Number of elements < val]   [ O(log(n)) ]
cout << *(se.find_by_order(i)); [value in index [i] ]        [ O(log(n)) ]

**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
      oset<int>s;
    }

    return 0;
}

/**************************      If need multiple same element     *-**************** *****/
/*************************       1 1 1 2 2 2 3 3 3 3 3 3 4 5 5 6    ***********************/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T> using oset = tree<T, null_type,
                         less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


/**

oset<int>se;                    [declear a set]
se.insert(val);                 [insert a value]             [ O(log(n)) ]
cout << se.order_of_key(val);   [Number of elements < val]   [ O(log(n)) ]
cout << *(se.find_by_order(i)); [value in index [i] ]        [ O(log(n)) ]

**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
      oset<int>s;
    }

    return 0;
}



