classDiagram
    note "Gamematch es clase abstracta"
class Gamematch {
    #string beatmap
    #int score
    #int performance_points
    #double accuracy
    #int num_notes
    #double star_rating

    #int great
    #int ok
    #int meh
    #int miss
    #int max_combo

    #calc_score()* int virtual
    #calc_performance()* int virtual
    #calc_accuracy()* void virtual
    +play()* virtual
    +show_results()* string virtual
    +get_performance_points() int
}

class Standard {
    +play()
    +show_results() string
    -calc_score() int
    -calc_performance() int
    -calc_accuracy() double
}

class Mania {
    -int num_keys
    -int perfect
    -int good

    +play()
    +show_results() string
    -calc_score() int
    -calc_performance() int
    -calc_accuracy() double

}

class Taiko {
    +play()
    +show_results() string
    -calc_score() int
    -calc_performance() int
    -calc_accuracy() double
}
Gamematch "0...N" --* "1" Player

class Player {
    -string name
    -int total_score
    -int performance_points
    -vector~Gamematch~ plays
    -calc_performance_point() int

    +Player()
    +show_stats() string
    +show_plays() string
    +new_standard(string bm, double star, int great, int ok, int meh, int miss, int max_combo) void
    +new_mania(string bm, double star, int great, int ok, int meh, int miss, int max_combo, int num_keys, int perfect, int good) void
    +new_taiko(std::string bm, double star, int great, int ok, int miss, int max_combo) void
}

Gamematch <|-- Standard
Gamematch <|-- Mania
Gamematch <|-- Taiko
