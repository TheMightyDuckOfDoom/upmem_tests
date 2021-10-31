#include <dpu>
#include <iostream>

using namespace dpu;

static constexpr int BUFFER_SIZE = 128;

int main() {
  try {
    auto system = DpuSet::allocate(1, "backend=simulator");
    auto dpu = system.dpus()[0];

    dpu->load("vector_add_kernel");

    std::cout << "Input: " << std::endl;
    std::vector<uint8_t> input(BUFFER_SIZE);
    for(int i = 0; i < BUFFER_SIZE; i++) {
      input[i] = (uint8_t) i;
      std::cout << i << " ";
    }
    std::cout << std::endl;
    dpu->copy("mram_array", input);
    dpu->exec();

    std::vector<std::vector<uint8_t>> output(1);
    output.front().resize(BUFFER_SIZE);
    dpu->copy(output, "mram_array");

    std::cout << "Output: " << std::endl;
    for(int i = 0; i < BUFFER_SIZE; i++) {
      std::cout << (uint32_t)output.front()[i] << " ";
    }
    std::cout << std::endl;
    dpu->log(std::cout);
  }
  catch(const DpuError &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}