## File Structure

```
 num_cry/
 ├── .gitignore
 ├── .vscode/
 └── settings.json
 ├── include/
    ├── array.hpp
    ├── lin_alg.hpp
    └── math_ops.hpp
 ├── main.cpp
 ├── num_cry.exe
 ├── Readme.md
 └── src/
    ├── array.cpp
    ├── lin_alg.cpp
    └── math_ops.cpp
```

## Compile using
```
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o num_cry
```

## Run using
```
./num_cry
```