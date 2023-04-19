```cpp
std::erase(std::remove_if(vec.begin(), vec.end(),
                          [](int x) { return x % 2 == 1; }),
           vec.end());
```

