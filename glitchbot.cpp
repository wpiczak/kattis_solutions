#include <iostream>
#include <vector>

std::pair<int, int> execute_instructions(const std::vector<int>& instructions) {
    int x = 0;
    int y = 0;
    int direction = 90;

    for (const int& instruction : instructions) {
        if (instruction == 0) {
            if (direction == 0) x += 1;
            else if (direction == 90) y += 1;
            else if (direction == 180) x -= 1;
            else if (direction == 270) y -= 1;
        } else if (instruction == 1) direction = (direction + 90) % 360;
        else if (instruction == 2) direction = (direction + 270) % 360;
    }

    return {x, y};
}

int main() {
    int destination_x, destination_y;
    std::cin >> destination_x >> destination_y;

    int instruction_count;
    std::cin >> instruction_count;

    std::vector<int> instructions;
    instructions.resize(instruction_count);

    for (int i = 0; i < instruction_count; ++i) {
        std::string instruction;
        std::cin >> instruction;

        if (instruction == "Forward") instructions[i] = 0;
        else if (instruction == "Left") instructions[i] = 1;
        else if (instruction == "Right") instructions[i] = 2;
    }

    for (int i = 0; i < instruction_count; ++i) {
        const int original_instruction = instructions[i];

        for (int j = 0; j < 3; ++j) {
            instructions[i] = j;
            if (execute_instructions(instructions) == std::pair{destination_x, destination_y}) {
                std::cout << i + 1 << ' ';
                if (j == 0) std::cout << "Forward";
                else if (j == 1) std::cout << "Left";
                else if (j == 2) std::cout << "Right";

                goto end;
            }
        }

        instructions[i] = original_instruction;
    }

end:
    return 0;
}
