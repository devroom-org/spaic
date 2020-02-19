# Spaic

> Single Page Application, In C++

Read like *spike*.

## Basic Idea

1. Emscripten let we compile C++ to WASM

1. We can write CSS in C++ like these syntax:

   ```c++
   auto greater_than_10 = css(
       backgroundColor = red,
       color = white,
   );
   ```

1. We can write React-like Component in C++ like these syntax:

    ```c++
    namespace Props {
        
    }
    public Node app() {
        auto [count, set_count] = use_state(false);
        return (
            div(
                className = (count > 10 && greater_than_10)
            )({
                "Hello! Your counter is ",
                count,
                button(
                    onClick = [] {
                        set_count([](previous) { previous + 1 })
                    }
                )({
                    "+1"
                }),
                button(
                    onClick = [] {
                        set_count([](previous) { previous + 1 })
                    }
                )({
                    "-1"
                })
            })
        );
    }
    ```

2. :tada: We can implement React-like API on C++

## Modules

- spaic-dui

    The declarative UI api

- spaic-css

    The CSS-in-C++ api

- spaic-dom

    The DOM renderer

- spaic

    The core runtime
