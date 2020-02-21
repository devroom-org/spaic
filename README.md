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
    #include <spaic/Prelude.hpp>

    namespace props::app {
        auto is_dark = fallback<bool>(false);

        auto all = prop_set(is_dark);
    }
    namespace state::app {
        auto [count, set_count] = use_state(0);

        auto all = state_set(count);
    }
    namespace msg {
        auto increment = app_msg<int>();
        auto decrement = app_msg<int>();
    }
    ShouldRender update(Msg&& msg) {
        if (increment == msg) {
            set_count([](previous) {
                return previous + increment[0];
            })
            return true;
        }
        if (decrement == msg) {
            set_count([](previous) {
                return previous - decrement[0];
            })
            return true;
        }
        return false;
    }
    Node render() {
        return (
            div(
                className = (count > 10 && greater_than_10)
            )({
                "Hello! Your counter is ",
                count,
                button(onClick = increment(1))({
                    "+1"
                }),
                button(onClick = decrement(1))({
                    "-1"
                })
            })
        );
    }

    auto app = create_component(
        props::app::all,
        state::app::all,

        update,
        render
    );
    ```

1. :tada: We can implement React-like API on C++

## Modules

- spaic-dui

    The declarative UI api

- spaic-css

    The CSS-in-C++ api

- spaic-dom

    The DOM renderer

- spaic

    The core runtime
