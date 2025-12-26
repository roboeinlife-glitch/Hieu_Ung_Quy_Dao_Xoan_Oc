#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 900;
const float PI = 3.14159265358979323846f;

// Hàm tạo màu ngẫu nhiên (hiện không dùng trong chương trình)
sf::Color getRandomColor() {
    return sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

int main() {
    // Khởi tạo seed cho hàm rand()
    srand(static_cast<unsigned int>(time(0)));

    // Tạo cửa sổ - đặt tên mới cho phù hợp với hiệu ứng
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Hiệu Ứng Quỹ Đạo Xoắn Ốc");
    window.setFramerateLimit(60);

    // Tạo đối tượng để tính toán vị trí các điểm (thay cho lục giác cũ)
    sf::CircleShape positionCalculator(30.f, 6); // Sử dụng để tính vị trí 6 điểm trên vòng tròn
    positionCalculator.setFillColor(sf::Color::Transparent);
    positionCalculator.setOutlineThickness(2);
    positionCalculator.setOrigin(30.f, 30.f);

    // Màu sắc cho các thành phần đồ họa
    sf::Color centerPointColor = sf::Color(255, 127, 80); // Màu cho điểm trung tâm di chuyển
    sf::Color radialLineColor = sf::Color::Black; // Màu đường bán kính từ tâm cửa sổ
    sf::Color shortLinesColor = sf::Color::Green; // Màu các đoạn thẳng ngắn
    sf::Color trajectoryColors[3] = {sf::Color::Yellow, sf::Color::Blue, sf::Color::Cyan}; // Màu các đường quỹ đạo

    // Biến điều khiển chuyển động
    float orbitAngle = 0.0f; // Góc di chuyển trên quỹ đạo xoắn ốc
    float rotationAngle = 0.0f; // Góc xoay của hệ thống điểm
    float orbitSpeed = 0.5f; // Tốc độ di chuyển trên quỹ đạo
    float rotationSpeed = 1.0f; // Tốc độ xoay hệ thống điểm
    float radius = 80.0f; // Bán kính hiện tại của quỹ đạo
    float spiralSpeed = 0.01f; // Tốc độ thay đổi bán kính (tạo hiệu ứng xoắn ốc)
    float minRadius = 40.0f; // Bán kính tối thiểu
    float maxRadius = 120.0f; // Bán kính tối đa

    // Vector lưu trữ các đường quỹ đạo
    std::vector<sf::VertexArray> trajectoryLines;

    // Vòng lặp chính
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Xóa màn hình
        window.clear(sf::Color::Black);

        // Tính toán tọa độ trung tâm của hệ thống theo quỹ đạo xoắn ốc
        radius += spiralSpeed;
        if (radius > maxRadius || radius < minRadius) {
            spiralSpeed *= -1; // Đảo chiều khi đạt giới hạn
        }

        // Vị trí trung tâm của hệ thống điểm
        float xCenter = WINDOW_WIDTH / 2 + radius * cos(orbitAngle);
        float yCenter = WINDOW_HEIGHT / 2 + radius * sin(orbitAngle);

        // Cập nhật vị trí và góc xoay cho bộ tính toán
        positionCalculator.setPosition(xCenter, yCenter);
        positionCalculator.setRotation(rotationAngle);
        positionCalculator.setOutlineColor(centerPointColor);
        window.draw(positionCalculator); // Vẽ điểm trung tâm

        // Vẽ đường bán kính từ tâm cửa sổ đến trung tâm hệ thống
        sf::VertexArray radiusLine(sf::Lines, 2);
        radiusLine[0].position = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
        radiusLine[1].position = positionCalculator.getPosition();
        radiusLine[0].color = radialLineColor;
        radiusLine[1].color = radialLineColor;
        window.draw(radiusLine);

        // Vẽ các đoạn thẳng ngắn tại 3 vị trí cách đều nhau (0, 2, 4)
        for (int j = 0; j < 6; j += 2) {
            sf::Vector2f startPoint = positionCalculator.getTransform().transformPoint(positionCalculator.getPoint(j));

            for (int k = 0; k < 2; ++k) {
                // Tính góc cho đoạn thẳng ngắn
                float shortLineAngle = rotationAngle + (k * 120 * PI / 180);
                float shortLineLength = 20.0f;
                sf::Vector2f shortLineEnd = startPoint + sf::Vector2f(cos(shortLineAngle), sin(shortLineAngle)) * shortLineLength;

                // Vẽ đoạn thẳng ngắn
                sf::VertexArray shortLine(sf::Lines, 2);
                shortLine[0].position = startPoint;
                shortLine[1].position = shortLineEnd;
                shortLine[0].color = shortLinesColor;
                shortLine[1].color = shortLinesColor;
                window.draw(shortLine);

                // Tạo đường quỹ đạo từ đầu đoạn thẳng ngắn
                sf::VertexArray trajectoryLine(sf::LinesStrip, 0);
                trajectoryLine.append(sf::Vertex(startPoint, trajectoryColors[k]));
                trajectoryLine.append(sf::Vertex(startPoint + sf::Vector2f(cos(shortLineAngle + PI / 2), sin(shortLineAngle + PI / 2)) * 30.0f, trajectoryColors[k]));
                trajectoryLines.push_back(trajectoryLine);
            }
        }

        // Vẽ tất cả các đường quỹ đạo
        for (const auto& line : trajectoryLines) {
            window.draw(line);
        }

        // Cập nhật góc cho chuyển động
        orbitAngle += -orbitSpeed * 0.01f;
        rotationAngle += rotationSpeed;

        // Giữ các góc trong phạm vi hợp lệ
        if (orbitAngle > 2 * PI) orbitAngle -= 2 * PI;
        if (rotationAngle > 360) rotationAngle -= 360;

        // Hiển thị
        window.display();
    }

    return 0;
}
