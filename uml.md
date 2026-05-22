classDiagram
    note "Partida es clase abstracta"
class Partida {
    #string beatmap
    #int puntuacion
    #int performance_points
    #double accuracy
    #int num_notas
    #double star_rating

    #int great
    #int ok
    #int meh
    #int miss
    #int max_combo

    #calc_puntuacion()* int virtual
    #calc_performance()* int virtual
    #calc_accuracy()* void virtual
    +jugar()* virtual
    +mostrar_resultados()* string virtual
    +get_performance_points() int
}

class Standard {
    +jugar()
    +mostrar_resultados() string
    -calc_puntuacion() int
    -calc_performance() int
    -calc_accuracy() double
}

class Mania {
    -int num_teclas
    -int perfect
    -int good

    +jugar()
    +mostrar_resultados() string
    -calc_puntuacion() int
    -calc_performance() int
    -calc_accuracy() double

}

class Taiko {
    +jugar()
    +mostrar_resultados() string
    -calc_puntuacion() int
    -calc_performance() int
    -calc_accuracy() double
}
Partida "0...N" --o "1" Jugador

class Jugador {
    -string nombre
    -int puntaje_total
    -int performance_points
    -vector~Partida~ partidas
    -calc_performance_point() int

    +Jugador()
    +mostrar_stats() string
}

Partida <|-- Standard
Partida <|-- Mania
Partida <|-- Taiko
