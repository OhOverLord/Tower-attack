#include "Game.h"
#include "Wall.h"
#include "Road.h"
#include "InvisibilityEffect.h"
#include "RegenerationEffect.h"
#include "ArmorEffect.h"
#include "HpEffect.h"
#include "DispersionEffect.h"
#include "EnhancementEffect.h"

Game::Game() {
    game_map = Map(0,0);
}

unsigned int Game::new_game(string file_name) {
    ifstream file;
    file.open(file_name, ios::in);
    if (!file.is_open() || file.fail()) {
        return 0;
    }

    vector<string> mapLines;
    string line;
    while (getline(file, line)) {
        mapLines.push_back(line);
    }
    file.close();

    if (mapLines.empty()) {
        return 0;
    }

    int mapHeight = mapLines.size();
    int mapWidth = mapLines[0].size();
    bool has_end = false, has_start = false;

    game_map = Map(mapWidth, mapHeight - 1);

    mapCopy.resize(mapHeight);
    for (int i = 0; i < mapHeight; i++) {
        if (mapLines[i].size() != mapWidth) {
            return 1;
        }
        mapCopy[i].resize(mapWidth);
        for (int j = 0; j < mapWidth; j++) {
            if (mapLines[i][j] == '#') {
                game_map.map[i][j] = new Wall('#', j, i);
                mapCopy[i][j] = '#';
            } else if (mapLines[i][j] == '<') {
                game_map.set_end(j, i);
                game_map.map[i][j] = new Road('<', j, i);
                has_end = true;
                mapCopy[i][j] = '<';
            } else if (mapLines[i][j] == '>') {
                game_map.set_start(j, i);
                game_map.map[i][j] = new Road('>', j, i);
                has_start = true;
                mapCopy[i][j] = '>';
            } else if (mapLines[i][j] == ' ') {
                game_map.map[i][j] = new Road(' ', j, i);
                mapCopy[i][j] = ' ';
            } else {
                return 1;
            }
        }
    }

    if (!has_end || !has_start) {
        return 1;
    }
    return 0;
}

unsigned int Game::read_settings() {
    ifstream file("examples/game_settings.txt");
    if (!file) {
        return 0;
    }

    int soldiers_count = 0;
    if (!(file >> soldiers_count)) {
        return 0;
    }
    for (int i = 0; i < soldiers_count; i++) {
        char type;
        int cost, hp, attack;
        if (!(file >> type >> cost >> hp >> attack)) {
            return 0;
        }
        soldiers.push_back(Soldier(cost, type, hp, attack));
    }

    int towers_count = 0;
    if (!(file >> towers_count)) {
        return 0;
    }
    for (int i = 0; i < towers_count; i++) {
        char type;
        int cost, hp, radius, attack;
        if (!(file >> type >> cost >> hp >> radius >> attack)) {
            return 0;
        }
        towers.push_back(Tower(cost, type, radius, hp, attack));
    }

    int soldiers_effects_count = 0;
    if (!(file >> soldiers_effects_count)) {
        return 0;
    }
    for (int i = 0; i < soldiers_effects_count; i++) {
        char type;
        int cost;
        string name;
        if (!(file >> type >> cost >> name)) {
            return 0;
        }
        if (name == "invisibility") {
            soldiers_effects.push_back(make_shared<InvisibilityEffect>(type, cost, name));
        } else if (name == "regeneration") {
            soldiers_effects.push_back(make_shared<RegenerationEffect>(type, cost, name));
        } else if (name == "armor") {
            soldiers_effects.push_back(make_shared<ArmorEffect>(type, cost, name));
        }
    }

    int towers_effects_count = 0;
    if (!(file >> towers_effects_count)) {
        return 0;
    }
    for (int i = 0; i < towers_effects_count; i++) {
        char type;
        int cost;
        string name;
        if (!(file >> type >> cost >> name)) {
            return 0;
        }
        if (name == "hp_upgrade") {
            towers_effects.push_back(make_shared<HpEffect>(type, cost, name));
        } else if (name == "dispersion") {
            towers_effects.push_back(make_shared<DispersionEffect>(type, cost, name));
        } else if (name == "enhancement") {
            towers_effects.push_back(make_shared<EnhancementEffect>(type, cost, name));
        }
    }
    return 1;
}

unsigned int Game::read_saved_settings() {
    ifstream file("examples/saved_settings.txt");
    if (!file) {
        return 0;
    }

    int soldiers_count = 0;
    if (!(file >> soldiers_count)) {
        return 0;
    }
    for (int i = 0; i < soldiers_count; i++) {
        char type;
        int cost, hp, attack;
        if (!(file >> type >> cost >> hp >> attack)) {
            return 0;
        }
        soldiers.push_back(Soldier(cost, type, hp, attack));
    }

    int towers_count = 0;
    if (!(file >> towers_count)) {
        return 0;
    }
    for (int i = 0; i < towers_count; i++) {
        char type;
        int cost, hp, radius, attack;
        if (!(file >> type >> cost >> hp >> radius >> attack)) {
            return 0;
        }
        towers.push_back(Tower(cost, type, radius, hp, attack));
    }

    int soldiers_effects_count = 0;
    if (!(file >> soldiers_effects_count)) {
        return 0;
    }
    for (int i = 0; i < soldiers_effects_count; i++) {
        char type;
        int cost;
        string name;
        if (!(file >> type >> cost >> name)) {
            return 0;
        }
        if (name == "invisibility") {
            soldiers_effects.push_back(make_shared<InvisibilityEffect>(type, cost, name));
        } else if (name == "regeneration") {
            soldiers_effects.push_back(make_shared<RegenerationEffect>(type, cost, name));
        } else if (name == "armor") {
            soldiers_effects.push_back(make_shared<ArmorEffect>(type, cost, name));
        }
    }

    int towers_effects_count = 0;
    if (!(file >> towers_effects_count)) {
        return 0;
    }
    for (int i = 0; i < towers_effects_count; i++) {
        char type;
        int cost;
        string name;
        if (!(file >> type >> cost >> name)) {
            return 0;
        }
        if (name == "hp_upgrade") {
            towers_effects.push_back(make_shared<HpEffect>(type, cost, name));
        } else if (name == "dispersion") {
            towers_effects.push_back(make_shared<DispersionEffect>(type, cost, name));
        } else if (name == "enhancement") {
            towers_effects.push_back(make_shared<EnhancementEffect>(type, cost, name));
        }
    }

    int army_count = 0;
    if (!(file >> army_count)) {
        return 0;
    }
    for (int i = 0; i < army_count; i++) {
        char default_type;
        if (!(file >> default_type)) {
            return 0;
        }
        add_new_soldier(default_type);
    }

    int defense_count = 0;
    if (!(file >> defense_count)) {
        return 0;
    }

    for (int i = 0; i < defense_count; i++) {
        char default_type;
        int x, y, hp, attack, cost, radius;
        if (!(file >> default_type >> x >> y >> hp >> attack >> cost >> radius)) {
            return 0;
        }
        Tower t = Tower(cost, default_type, radius, hp, attack);
        t.x = x;
        t.y = y;
        defense.push_back(make_shared<Tower>(t));
        game_map.map[y][x]->type = default_type;
    }

    int round;
    if (!(file >> round)) {
        return 0;
    }
    this->round = round;

    int money;
    if (!(file >> money)) {
        return 0;
    }
    this->money = money;

    int score;
    if (!(file >> score)) {
        return 0;
    }
    this->score = score;
    return 1;
}

unsigned int Game::save_game() {
    std::ofstream file;

    file.open("examples/saved_map.txt", std::ios::out);
    if (!file.is_open() || file.fail()) {
        return 0;
    }

    for (unsigned int i = 0; i < game_map.map.size(); i++) {
        for (unsigned int j = 0; j < game_map.map.at(i).size(); j++) {
            if (game_map.map.at(i).at(j)->type == '#' ||
                game_map.map.at(i).at(j)->type == '>' || game_map.map.at(i).at(j)->type == '<')
                file << game_map.map.at(i).at(j)->type;
            else
                file << ' ';
        }
        file << endl;
    }
    file << endl;

    file.close();

    file.open("examples/saved_settings.txt", std::ios::out);
    if (!file.is_open() || file.fail()) {
        return 0;
    }

    file << soldiers.size() << std::endl;
    for (const auto& soldier : soldiers) {
        file << soldier.get_type() << " " << soldier.get_cost() << " " << soldier.get_hp() << " " << soldier.get_attack() << std::endl;
    }

    file << towers.size() << std::endl;
    for (const auto& tower : towers) {
        file << tower.get_type() << " " << tower.get_cost() << " " << tower.get_hp() << " " << tower.get_radius() << " " << tower.get_attack() << std::endl;
    }

    file << soldiers_effects.size() << std::endl;
    for (const auto& effect : soldiers_effects) {
        file << effect->type << " " << effect->cost << " " << effect->name << std::endl;
    }

    file << towers_effects.size() << std::endl;
    for (const auto& effect : towers_effects) {
        file << effect->type << " " << effect->cost << " " << effect->name << std::endl;
    }

    file << army.size() << std::endl;
    for (const auto& soldier : army) {
        file << soldier->default_type << std::endl;
    }
    file << defense.size() << std::endl;
    for (const auto& tower : defense) {
        file << tower->default_type << " " << tower->x << " " << tower->y << " " << tower->get_hp() << " " << tower->get_attack() << " " << tower->get_cost() << " " << tower->get_radius() << std::endl;
    }
    file << round << endl;
    file << money << endl;
    file << score << endl;
    file.close();

    return 1;
}

unsigned int Game::add_new_soldier(char type) {
    int i = 0;
    for (const auto& soldier : soldiers) {
        if (soldier.get_type() == type) {
            break;
        }
        i++;
    }
    if (i == soldiers.size())
        return 1;
    if (soldiers[i].get_cost() > money)
        return 2;
    money -= soldiers[i].get_cost();
    army.push_back(make_shared<Soldier>(soldiers[i]));
    return 0;
}

unsigned int Game::add_new_tower(char type) {
    int i = 0;
    for (const auto& tower : towers) {
        if (tower.get_type() == type) {
            break;
        }
        i++;
    }
    if (i == soldiers.size())
        return 1;
    defense.push_back(make_shared<Tower>(towers[i]));
    return 0;
}

unsigned int Game::add_soldier_effect(char type) {
    int i = 0;
    for (const auto& ef : soldiers_effects) {
        if (ef->type == type) {
            break;
        }
        i++;
    }
    if (i == soldiers_effects.size())
        return 1;
    if(army.empty())
        return 3;
    if (soldiers_effects[i]->cost > money)
        return 2;
    money -= soldiers_effects[i]->cost;
    for (auto& soldier : army) {
        soldier->effects.push_back(soldiers_effects[i]);
    }
    return 0;
}

unsigned int Game::add_tower_effect(int type) {
    for (auto &tower: defense) {
        tower->effects.push_back(towers_effects[type]);
    }
    return 0;
}

void Game::clean_map() {
    for (unsigned int i = 0; i < game_map.map.size(); i++) {
        for (unsigned int j = 0; j < game_map.map.at(i).size(); j++) {
            game_map.map[i][j]->status = -1;
            game_map.map[i][j]->before = nullptr;
        }
    }
}

void Game::exit_game() {
    for (unsigned int i = 0; i < game_map.map.size(); i++) {
        for (unsigned int j = 0; j < game_map.map.at(i).size(); j++) {
            delete game_map.map.at(i).at(j);
            game_map.map.at(i).at(j) = nullptr;
        }
    }
}

unsigned int Game::move_soldiers() {
    int i = 0, j = 0;
    army_cnt++;
    for (auto it = army.begin(); it != army.end(); ) {
        auto& soldier = *it;
        if (i == army_cnt)
            return 1;

        int currentX = soldier->get_x();
        int currentY = soldier->get_y();

        if (soldier->is_alive() && soldier->get_path_index() != game_map.soldiers_path.size()) {
            for (auto itTower = defense.begin(); itTower != defense.end(); ) {
                auto& tower = *itTower;
                int towerX = tower->x;
                int towerY = tower->y;
                int soldierX = soldier->get_x();
                int soldierY = soldier->get_y();

                if(soldier->invisibility)
                    break;

                int distance = abs(towerX - soldierX) + abs(towerY - soldierY);
                if ((distance <= tower->get_radius())) {
                    soldier->damage(tower->get_attack());
                    tower->damage(soldier->get_attack());
                    break;
                }

                if (!tower->is_alive()) {
                    tower->die();
                    game_map.map[tower->y][tower->x]->type = tower->type;
                    mapCopy[tower->y][tower->x] = tower->type;
                    itTower = defense.erase(itTower);
                    score++;
                    continue;
                }
                ++itTower;
            }

            if (!soldier->is_alive()) {
                soldier->die();
                game_map.map[currentY][currentX]->type = soldier->type;
                mapCopy[currentY][currentX] = soldier->type;
                soldier->effects.clear();
                it = army.erase(it);
                continue;
            }

            int nextX = game_map.soldiers_path[soldier->get_path_index()]->x;
            int nextY = game_map.soldiers_path[soldier->get_path_index()]->y;

            soldier->set_x(nextX);
            soldier->set_y(nextY);
            soldier->set_path_index(soldier->get_path_index() + 1);
            game_map.map[currentY][currentX]->type = mapCopy[currentY][currentX];
            game_map.map[nextY][nextX]->type = soldier->type;

            ++it;
        } else {
            int endX = game_map.soldiers_path[soldier->get_path_index() - 1]->x;
            int endY = game_map.soldiers_path[soldier->get_path_index() - 1]->y;
            game_map.map[endY][endX]->type = mapCopy[endY][endX];
            j++;
            ++it;
        }
        i++;
    }

    if(army.empty()) {
        army_cnt = 0;
        return 2;
    }
    if (j == army.size()) {
        for(auto & soldier : army)
            money += soldier->get_cost() * 1.5;
        army_cnt = 0;
        return 0;
    }
    return 1;
}


void Game::added_towers() {
    towers_cnt = defense.size();
    for (int i = towers_cnt; i <= towers_cnt + 1; i++)
        add_new_tower('I');

    int radius = 1;

    int randomIndex = rand() % (game_map.soldiers_path.size() - 2);
    for (int i = randomIndex; i < game_map.soldiers_path.size() - 2; i++) {
        int x = game_map.soldiers_path[i]->x;
        int y = game_map.soldiers_path[i]->y;

        vector<pair<int, int>> freeCells;

        for (int dx = -radius; dx <= radius; dx++) {
            for (int dy = -radius; dy <= radius; dy++) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < game_map.get_width() && ny >= 0 && ny < game_map.get_height()) {
                    if (game_map.map[ny][nx]->type != 'I' && game_map.map[ny][nx]->type != '#' && game_map.map[ny][nx]->type != '<' && game_map.map[ny][nx]->type != '>') {
                        freeCells.push_back(make_pair(nx, ny));
                    }
                }
            }
        }

        if (!freeCells.empty()) {
            int randomCellIndex = rand() % freeCells.size();
            int bx = freeCells[randomCellIndex].first;
            int by = freeCells[randomCellIndex].second;

            bool isPathCoordinate = false;
            for (int j = 0; j < game_map.soldiers_path.size(); j++) {
                if (bx == game_map.soldiers_path[j]->x && by == game_map.soldiers_path[j]->y) {
                    isPathCoordinate = true;
                    break;
                }
            }

            if (!isPathCoordinate) {
                defense[towers_cnt]->x = bx;
                defense[towers_cnt]->y = by;
                game_map.map[by][bx]->type = defense[towers_cnt]->type;
                towers_cnt++;

                if (towers_cnt == defense.size()) {
                    break;
                }
            }
        }
    }
}

void Game::clear_obstacles() {
    for (unsigned int i = 0; i < game_map.map.size(); i++) {
        for (unsigned int j = 0; j < game_map.map.at(i).size(); j++) {
            if (game_map.map.at(i).at(j)->get_type() == 'X' || game_map.map.at(i).at(j)->get_type() == '%') {
                game_map.map.at(i).at(j)->type = ' ';
                mapCopy[i][j] = ' ';
            }
        }
    }
}