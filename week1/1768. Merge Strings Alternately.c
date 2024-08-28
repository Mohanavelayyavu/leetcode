 bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int maxCandies = candies[0];
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }
    
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= maxCandies) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }
    
    *returnSize = candiesSize;
    
    return result;
}
