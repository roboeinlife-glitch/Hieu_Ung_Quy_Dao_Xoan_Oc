# Hiệu Ứng Quỹ Đạo Xoắn Ốc - Spiral Orbital Trajectory Effect

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![SFML](https://img.shields.io/badge/SFML-2.5-green.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)

Một chương trình đồ họa mô phỏng hiệu ứng chuyển động quỹ đạo xoắn ốc với các đường quỹ đạo phức tạp, được phát triển bằng C++ và thư viện SFML.

## ✨ Đặc điểm nổi bật

- **Hiệu ứng hình ảnh động**: Tạo ra các đường quỹ đạo xoắn ốc với màu sắc sống động
- **Chuyển động mượt mà**: Hệ thống điểm di chuyển theo quỹ đạo thay đổi bán kính
- **Đa dạng màu sắc**: Sử dụng nhiều màu khác nhau cho các thành phần đồ họa
- **Tốc độ tùy chỉnh**: Có thể điều chỉnh tốc độ xoay và di chuyển

## 🎥 Hiệu ứng hình ảnh

*(Bạn có thể thêm ảnh chụp màn hình hoặc GIF tại đây)*

![Demo](https://www.youtube.com/shorts/HPxQiB41GaA)) 

## 🛠️ Công nghệ sử dụng

- **Ngôn ngữ**: C++17
- **Thư viện đồ họa**: SFML 2.5 (Simple and Fast Multimedia Library)
- **Compiler**: MinGW/GCC (Windows) hoặc GCC/Clang (Linux/macOS)
- **IDE**: Code::Blocks (có thể dùng Visual Studio, CLion, etc.)


## 🚀 Cách cài đặt và chạy

### **Yêu cầu hệ thống**
- SFML 2.5 hoặc cao hơn
- Compiler C++ hỗ trợ C++17
- Hệ điều hành: Windows, Linux, hoặc macOS

### **Cài đặt trên Windows (Code::Blocks)**
1. Tải và cài đặt [Code::Blocks](http://www.codeblocks.org/)
2. Tải [SFML](https://www.sfml-dev.org/download.php) cho MinGW
3. Tạo project mới trong Code::Blocks
4. Thêm file `main.cpp` vào project
5. Cấu hình linker với các thư viện SFML:
   - `sfml-graphics`
   - `sfml-window`
   - `sfml-system`
6. Build và chạy chương trình

## **Tuỳ chỉnh tham số**

// Tốc độ di chuyển
float orbitSpeed = 0.5f;

// Tốc độ xoay
float rotationSpeed = 1.0f;

// Bán kính quỹ đạo
float minRadius = 40.0f;
float maxRadius = 120.0f;

// Màu sắc các thành phần
sf::Color shortLinesColor = sf::Color::Green;
sf::Color trajectoryColors[3] = {sf::Color::Yellow, sf::Color::Blue, sf::Color::Cyan};

Chương trình được tạo bởi sự kết hợp giữa Grok AI (xAI) và DeepSeek AI

[Demo](https://www.youtube.com/shorts/HPxQiB41GaA)

[Trở về trang chủ](https://github.com/roboeinlife-glitch)
