#include "GameScreen.h"
#include "Game.h"
#include <fstream>

GameScreen::GameScreen() : Screen() {
}

GameScreen::~GameScreen() {
}

unsigned int GameScreen::show() {
    unsigned int res = game.new_game("examples/game_map.txt");
    unsigned int read_settings = game.read_settings();

    if(!res || !read_settings)
    {
        show_error(1);
        wgetch(window);
        return 0;
    }
    unsigned int height = show_map();

    show_info();
    show_input(height, 5);
    wclear(window);
    wrefresh(window);
    return 0;
}

unsigned int GameScreen::draw_map() {
    unsigned int height = 6;
    for (unsigned int i = 0; i < game.game_map.map.size(); i++) {
        for (unsigned int j = 0; j < game.game_map.map.at(i).size(); j++) {
            mvwaddch(window, height, ((getmaxx(window) - game.game_map.map.at(i).size()) / 2) + j,
                     game.game_map.map.at(i).at(j)->get_type());
        }
        height++;
    }
    return height;
}

unsigned int GameScreen::show_map() {
    game.game_map.find_soldiers_path();
    game.added_towers();

    int height = draw_map();
    height++;

    string soldiers_header = "Soldiers:";
    int soldiers_header_x = (getmaxx(window) - soldiers_header.size()) / 2;
    mvwaddstr(window, height++, soldiers_header_x, soldiers_header.c_str());

    int column_width = 10;

    int soldiers_table_x = (getmaxx(window) - (4 * column_width)) / 2;
    mvwprintw(window, height, soldiers_table_x, "%-*s", column_width, "Name");
    mvwprintw(window, height, soldiers_table_x + column_width, "%-*s", column_width, "HP");
    mvwprintw(window, height, soldiers_table_x + (2 * column_width), "%-*s", column_width, "$$$");
    mvwprintw(window, height, soldiers_table_x + (3 * column_width), "%-*s", column_width, "Attack");
    height++;

    for (unsigned int i = 0; i < game.soldiers.size(); i++) {
        Soldier soldier = game.soldiers[i];
        mvwprintw(window, height, soldiers_table_x, "%-*c", column_width, soldier.get_type());
        mvwprintw(window, height, soldiers_table_x + column_width, "%-*d", column_width, soldier.get_hp());
        mvwprintw(window, height, soldiers_table_x + (2 * column_width), "%-*d", column_width, soldier.get_cost());
        mvwprintw(window, height, soldiers_table_x + (3 * column_width), "%-*d", column_width, soldier.get_attack());
        height++;
    }
    height++;

    string soldiers_effects_header = "Effects:";
    int soldiers_effects_header_x = (getmaxx(window) - soldiers_header.size()) / 2;
    mvwaddstr(window, height++, soldiers_effects_header_x, soldiers_effects_header.c_str());

    int soldiers_effects_table_x = (getmaxx(window) - (4 * column_width)) / 2;
    mvwprintw(window, height, soldiers_effects_table_x, "%-*s", column_width, "Name");
    mvwprintw(window, height, soldiers_effects_table_x + column_width, "%-*s", column_width, "$$$");
    mvwprintw(window, height, soldiers_effects_table_x + (2 * column_width), "%-*s", column_width, "What?");
    height++;

    for (unsigned int i = 0; i < game.soldiers_effects.size(); i++) {
        SoldierEffect * effect = game.soldiers_effects[i].get();
        mvwprintw(window, height, soldiers_effects_table_x, "%-*c", column_width, effect->type);
        mvwprintw(window, height, soldiers_effects_table_x + column_width, "%-*d", column_width, effect->cost);
        mvwprintw(window, height, soldiers_effects_table_x + (2 * column_width), "%-*s", column_width, effect->name.c_str());
        height++;
    }
    wrefresh(window);
    return height;
}

void GameScreen::show_info() {
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    wattron(window, COLOR_PAIR(2));
    string round = "Round: " + to_string(game.round);
    mvwaddstr(window, 2, (getmaxx(window) - round.size()) / 2, round.c_str());

    string money = "Money: " + to_string(game.money);
    mvwaddstr(window, 3, (getmaxx(window) - money.size()) / 2, money.c_str());

    string score = "Score: " + to_string(game.score);
    mvwaddstr(window, 4, (getmaxx(window) - score.size()) / 2, score.c_str());
    wattroff(window, COLOR_PAIR(2));
}

unsigned int GameScreen::show_army(unsigned int height, unsigned int padding) {
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    unsigned int y = height + 2;
    string army_title = "Army: ";
    wattron(window, COLOR_PAIR(5));
    mvwaddstr(window, y, padding, army_title.c_str());
    wattroff(window, COLOR_PAIR(5));
    int x = padding + army_title.size();
    for(int i = 0; i < game.army.size(); i++)
    {
        mvwaddch(window, y, x, static_cast<char>(game.army[i]->get_type()));
        x++;
    }
    return y;
}

unsigned int GameScreen::show_input(unsigned int height, unsigned int padding) {
    unsigned int y = height + 2;
    string title = "Command: ";
    unsigned int x = 5 + title.size();
    mvwaddstr(window, y, padding, title.c_str());
    wmove(window, y, padding + title.size() + 1);
    wrefresh(window);
    noecho();
    curs_set(true);

    keypad(window, true);
    string user_input = "";
    int ch = 0;

    while(true) {
        ch = wgetch(window);
        if(ch == 9) {
            curs_set(false);
            return 0;
        }
        else if(ch == 10)
        {
            int res = execute_input(user_input);
            if(res == 3)
            {
                curs_set(false);
                return 0;
            }
            wmove(window, 2, 0);
            wclrtoeol(window);
            wmove(window, 3, 0);
            wclrtoeol(window);
            show_info();
            if(!game.army.empty())
                show_army(0, padding);
            user_input = "";
            x = 5 + title.size();

            wmove(window, y, x);
            wclrtoeol(window);
            wmove(window, y, x);
            wrefresh(window);
        }
        else if(ch == KEY_BACKSPACE || ch == KEY_DC|| ch == 127)
        {
            if(!user_input.empty()) {
                user_input.pop_back();
                x--;
                wmove(window, y, x);
                mvwaddch(window, y, x, ' ');
                wmove(window, y, x);
            }
        } else if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT || ch == KEY_RIGHT || ch == 27)
            continue;
        else {
            wmove(window, 0, 0);
            wclrtoeol(window);
            user_input += static_cast<char>(ch);
            mvwaddch(window, y, x, static_cast<char>(ch));
            x++;
        }
    }
}

void GameScreen::remove_soldiers_effects() {
    for (auto& soldier : game.army) {
        for(auto & eff : soldier->effects) {
            eff->remove(soldier.get());
        }
        soldier->effects.clear();
        soldier->type = soldier->default_type;
    }
}

// void GameScreen::remove_towers_effects() {
//     if(!game.defense.empty())
//     {
//         for (auto& tower : game.defense) {
//             for(auto & eff : tower->effects) {
//                 eff->remove(tower.get());
//             }
//             tower->effects.clear();
//             tower->type = tower->default_type;
//             game.game_map.map[tower->y][tower->x]->type = tower->type;
//         }
//     }
// }

void GameScreen::add_towers_effects() {
    for(int i = 0; i < rand() % 3; i++)
        game.add_tower_effect(i);
    for (auto& tower : game.defense) {
        for(auto & eff : tower->effects) {
            eff->apply(tower.get());
            tower->type = eff->type;
        }
        if(tower->effects.size() == 2) {
            tower->type = '2';
        }
        else if(tower->effects.size() == 3) {
            tower->type = '3';
        }
        game.game_map.map[tower->y][tower->x]->type = tower->type;
    }
}

unsigned int GameScreen::execute_input(string input) {
    init_pair(4, COLOR_RED, COLOR_BLACK);
    if (input == "start" && !game.army.empty()) {
        if(game.round != 0)
            game.clean_map();
        curs_set(false);
        game.game_map.find_soldiers_path();
        for (auto& soldier : game.army) {
            soldier->set_x(game.game_map.soldiers_path[1]->x);
            soldier->set_y(game.game_map.soldiers_path[1]->y);
            soldier->set_path_index(1);
        }
        game.alive_soldiers = game.army.size() - 1;
        if(game.round % 2 == 0)
            add_towers_effects();
        draw_map();
        while (true) {
            unsigned int result = game.move_soldiers();
            draw_map();
            if(result == 2)
            {
                if(game.army.empty() && game.money < 50)
                {
                    string lostMessage = "You have lost! Press any key to exit the game.";
                    wattron(window, COLOR_PAIR(4));
                    mvwaddstr(window, 0, (getmaxx(window) - lostMessage.size()) / 2, lostMessage.c_str());
                    wattroff(window, COLOR_PAIR(4));
                    wgetch(window);
                    game.exit_game();
                    return 3;
                }
                // remove_towers_effects();
                game.clear_obstacles();
                draw_map();
                show_army(0, 5);
                return 0;
            }
            if(result == 0)
            {
                if(game.round == 10) {
                    string wonMessage = "You have won the game! Press any key to exit.";
                    wattron(window, COLOR_PAIR(5));
                    mvwaddstr(window, 0, (getmaxx(window) - wonMessage.size()) / 2, wonMessage.c_str());
                    wattroff(window, COLOR_PAIR(5));
                    wgetch(window);
                    game.exit_game();
                    return 3;
                }
                game.round++;
                game.added_towers();
                game.clear_obstacles();
                // remove_towers_effects();
                draw_map();
                remove_soldiers_effects();
                show_army(0, 5);
                return 0;
            }
            usleep(80000);
            wrefresh(window);
        }
    } else if (input == "exit") {
        game.exit_game();
        return 3;
    } else {
        string command, name, check, soldier_name;
        istringstream ss(input, istringstream::in);
        ss >> command;
        if (command == "add") {
            ss >> name;
            if (name == "") {
                string error = "ERROR: Soldier name is missing!";
                wattron(window, COLOR_PAIR(4));
                mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
                wattroff(window, COLOR_PAIR(4));
            }
            int status = game.add_new_soldier(name[0]);
            if (status == 0) {
                return 0;
            } else if (status == 1) {
                string error = "ERROR: Oh... I think... The name of the soldier is wrong! Do you think so?";
                wattron(window, COLOR_PAIR(4));
                mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
                wattroff(window, COLOR_PAIR(4));
            } else if (status == 2) {
                string error = "ERROR: Not enough money!";
                wattron(window, COLOR_PAIR(4));
                mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
                wattroff(window, COLOR_PAIR(4));
            }
        }
        else if(command == "effect")
        {
            ss >> name;
            if (name == "") {
                string error = "ERROR: Effect name is missing!";
                wattron(window, COLOR_PAIR(4));
                mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
                wattroff(window, COLOR_PAIR(4));
            }
            int status = game.add_soldier_effect(name[0]);
            if (status == 0) {
                for (auto& soldier : game.army) {
                    for(auto & eff : soldier->effects) {
                        eff->apply(soldier.get());
                        soldier->type = eff->type;
                    }
                    if(soldier->effects.size() == 2)
                        soldier->type = ':';
                    else if(soldier->effects.size() == 3)
                        soldier->type = ';';
                }
                show_army(0, 5);
                return 0;
            } else if (status == 1) {
                string error = "ERROR: Oh... I think... The name of the effect is wrong! Do you think so?";
                wattron(window, COLOR_PAIR(4));
                mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
                wattroff(window, COLOR_PAIR(4));
            } else if (status == 2) {
                string error = "ERROR: Not enough money!";
                wattron(window, COLOR_PAIR(4));
                mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
                wattroff(window, COLOR_PAIR(4));
            } else if (status == 3) {
                string error = "ERROR: Army is empty!";
                wattron(window, COLOR_PAIR(4));
                mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
                wattroff(window, COLOR_PAIR(4));
            }
        }
        else if(command == "save") {
            unsigned int result = game.save_game();
            if (result == 0) {
                show_error(0);
                wgetch(window);
            }
            return 0;
        }
        else if(command == "win")
        {
            string wonMessage = "You have won the game! Press any key to exit.";
            wattron(window, COLOR_PAIR(2));
            mvwaddstr(window, 0, (getmaxx(window) - wonMessage.size()) / 2, wonMessage.c_str());
            wattroff(window, COLOR_PAIR(2));
            wgetch(window);
            game.exit_game();
            return 3;
        }
        else {
            string error = "ERROR: Wrong command!";
            wattron(window, COLOR_PAIR(4));
            mvwaddstr(window, 0, (getmaxx(window) - error.size()) / 2, error.c_str());
            wattroff(window, COLOR_PAIR(4));
        }
    }
    wrefresh(window);
    return 1;
}