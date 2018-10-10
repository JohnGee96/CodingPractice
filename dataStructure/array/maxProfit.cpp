// Problem: Given a list of day stock prices, 
//          find the maximum single sell profit

// In other words: max difference between two endpoints in an array
#include <iostream>
#include <tuple>

using namespace std;
/*
 * current profit = INT_MIN
 * current buy = stock_prices[0]
 * global sell = stock_prices[1]
 * global profit = global sell - current buy
 * For i = 1 to stock_prices.length:
 *    current profit = stock_prices[i] - current buy
 *    if current profit is greater than global profit 
 *        then update global profit to current profit and update global sell to stock_prices[i]
 *    if stock_prices[i] is less than current buy then update current buy to stock_prices[i]
 * return global profit and global sell
 */


tuple<int,int> find_buy_sell_stock_prices(int a[], int size) { 

    int global_sell = a[1];
    int curr_buy = a[0];
    int global_profit = global_sell - curr_buy;
    int curr_profit = INT_MIN;

    for (int i=1; i<size; ++i) {
        curr_profit = a[i] - curr_buy;
        if (curr_profit > global_profit) {
            global_profit = curr_profit;
            global_sell = a[i];
        }
        if (a[i] < curr_buy)
            curr_buy = a[i];
    }

    tuple<int,int> result(make_pair(global_sell - global_profit, global_sell));

    return result;
}

int main() {
    int a1[] = {8, 5, 12, 3, 11, 1};
    int len1 = sizeof(a1) / sizeof(int);

    tuple<int, int> result1 = find_buy_sell_stock_prices(a1, len1);
    cout << "Buy/Sell: " << get<0>(result1) << ' ' << get<1>(result1) << '\n';
    cout << "Expected Result: 3 11" << '\n';

    int a2[] = {21, 12, 11, 9, 6, 3};
    int len2 = sizeof(a2) / sizeof(int);

    tuple<int, int> result2 = find_buy_sell_stock_prices(a2, len2);
    cout << "Buy/Sell: " << get<0>(result2) << ' ' << get<1>(result2) << '\n';
    cout << "Expected Result: 12 11" << '\n';

    return 0;
}