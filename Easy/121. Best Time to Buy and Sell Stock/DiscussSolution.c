int maxProfit(int* prices, int pricesSize) {
    int minprice = INT_MAX, maxprofit = 0, i = 0;

    for (i = 0; i < pricesSize; i++) {
        if (prices[i] < minprice) {
            minprice = prices[i];
        } else if (prices[i] - minprice > maxprofit) {
            maxprofit = prices[i] - minprice;
        }
    }

    return maxprofit;
}
