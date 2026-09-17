# Trial II — *The Critique*

*Warden of the Foundations · Midterm 1 · 15 %*

This trial **requires** you to use an LLM. You will paste the prompt and the reply, then critique what you got. Reading and judging AI output is part of the job now; we are practicing it on purpose.

---

## The prompt

Open Claude (or your LLM of choice) and paste **this exact prompt**:

> *Write a C++ function template that returns the largest element of a `std::vector<T>`. Handle the case where the vector is empty. Briefly explain your design choices.*

Tell us which tool you used and the date: ChatGPT, 2026-09-16

- **Tool:** (e.g., Claude / ChatGPT / Copilot Chat / …)
- **Date of the conversation:** YYYY-MM-DD

---

## The LLM's reply

Paste the **full reply**, code and prose. Use a fenced code block for the code. Do not edit the reply — we want to see what you actually got.

```cpp
#include <vector>
#include <stdexcept>

template <typename T>
T findLargest(const std::vector<T>& values) {
    if (values.empty()) {
        throw std::invalid_argument("Vector is empty");
    }

    T largest = values[0];

    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] > largest) {
            largest = values[i];
        }
    }

    return largest;
}
```

template <typename T> makes the function work with different data types, such as int, double, or string.
const std::vector<T>& avoids copying the vector while preventing the function from modifying it.
Empty vector: The function throws std::invalid_argument because there is no largest element to return.
values[0] is used to initialize largest, then the remaining elements are compared against it.
The function uses > to determine which element is larger.

---

## My critique  *( ≥ 150 words )*

Your critique must read like an engineer reviewing a colleague's pull request — specific, technical, and naming exactly what the LLM did. A vague critique ("looks fine to me, but it could be better") is *not* full credit even if the LLM's code was great.

Address each of these:

- **Compile.** Did you actually try to compile and run the code? On what types? What happened?
- **Empty case.** What does the empty-vector case actually do in this code? Is the LLM's choice reasonable? Is it different from what *you* would have chosen?
- **Requirements on `T`.** What does the code require of `T`? What happens if you instantiate it with a type that doesn't support `<` (e.g., a custom struct)?
- **Const-correctness.** Pass by value or by reference? Return by value or by reference? Would you change either?
- **`std::max_element`?** Did the LLM cheat by using the algorithm header, or did it write the loop? Which would *you* have shipped, and why?
- **One concrete improvement.** Name one specific change you would make before merging this into a real project. Not "make it better" — a concrete code change.

(your critique — at least 150 words)
