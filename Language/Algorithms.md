1. 生成 `[0, n-1]` 的数列。

   ```cpp
    vector<int> fa(n);
    std::iota(fa.begin(), fa.end(), 0);
   ```

2. 计算数组前缀和

   ```cpp
   std::vector<int> nums {1, 2, 3, 4}; // 原数组
   std::vector<int> s (a.size() + 1); // 前缀和
   std::partial_sum(nums.begin(), nums.end(), s.begin() + 1);
   ```

3. 求和

   ```cpp
   std::vector<int> nums {1, 2, 3, 4}; // 原数组
   auto sum = std::accumulate(nums.begin(), nums.end(), 0);
   ```

4. 求最值

   ```cpp
   int mx = *std::max_element(nums.begin(), nums.end()); // 最大值
   int mn = *std::min_element(nums.begin(), nums.end()); // 最小值
   ```

5. 自定义排序规则

   ```cpp
   std::vector<std::pair<int, int>> arr {{1, 2}, {3, 3}, {2, 1}};
   
   // 对数组按照按照第二关键字升序，第一关键字降序排列
   std::sort(arr.begin(), arr.end(), [](auto& lhs, auto& rhs) {
     return lhs.second < rhs.second ||
       		 lhs.second == rhs.second && lhs.second > rhs.second;
   });
   ```

6. 二分查找

   ```cpp
   std::sort(nums.begin(), nums.end()); // 对数组进行升序排序
   
   // 找到第一个 >= x 的位置
   auto pos1 = std::lower_bound(nums.begin(), nums.end(), x) - nums.begin();
   
   // 找到第一个 > x 的位置
   auto pos2 = std::upper_bound(nums.begin(), nums.end(), x) - nums.begin();
   ```

7. 排序 + 去重

   ```cpp
   std::sort(arr.begin(), arr.end());
   std::erase(std::unique(arr.begin(), arr.end()),
              arr.end());
   ```

8. 