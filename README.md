# Simulador de osu! 
## Contexto
[osu!](https://osu.ppy.sh/) es un juego de ritmo inspirado en el juego [Osu! Tatakae! Ouendan](https://en.wikipedia.org/wiki/Osu!_Tatakae!_Ouendan) para la Nintendo DS. En sus inicios osu! se limitó a emular a este juego. Con el tiempo, pasó a incluir diferentes modos de juego: osu!taiko basado en [Taiko no Tatsujin](https://es.wikipedia.org/wiki/Taiko_no_Tatsujin), osu!catch y osu!mania (similar a Piano Tiles).

Cada uno de los modos de juego cuenta con diferentes mecánicas, las cuales hacen que sea necesario procesar las partidas de forma diferente para obtener la puntuación y los [puntos de rendimiento](https://osu.ppy.sh/wiki/es/Performance_points).

## Funcionalidad
Este programa busca hacer una implementación del sistema de partidas utilizando POO para reutilizar el código que se comparte entre todos los modos de juego y usar polimorfismo para calcular los resultados de una partida.

El programa permite simular una partida jugada para ver su puntuación y puntos de rendimiento correspondientes.

También permite calcular los puntos de rendimiento totales de un jugador en base a sus partidas.

## Diagrama de Clases
![](https://mermaid.ink/svg/pako:eNq1VNuK2zAQ_RWhEujFDvGtXpu-bZ8KC4X2qRjMxJok2tqSkeTSbZp_r-Rb4uzmbes3HZ3xnDkzmiOtJEOa09XqSLjghuTkSApqDthgQe2poAx30NXGnk6n1aoQVQ1af-awV9AUgthPSIOW-BWU4QwIauI4SGCrjYLKQEHHMDJxjkPkG0vgYk-2CKaBdgS5MKTthOmg4lJcgqh2UjUgKixbaRE9XjLZbWubsKo6m_DpIkR0TWn1gWUO6IfHbg_q7bv35BdXNkU9whXUVXnO6ggu_iXSWcXLrEa6ulWpUFvjgEnteGOpM_XkFA2ufDMgGCg22eJPynXNGSq9VH5LsFNyU-dweZHzAQSHZwkPsmbOL9RXFwZd2KsJWUj5DvynnKWMvdSVknVd6haR_Y_678FUh-eGG4XQvKrh08h_-uv7c6ev4L4ZV1jvyhXWiz7X8MXqY1LNVYwjJmSzVXhRmRMNj1ga-xDqS_zGexqLGn8_GzDNtTZgtEN7Owsxj6_vy0lTIYYBW0BDoxfQ0IYFRD26V5zR3KgOPdqgVeiOtC9zXk6L3WS12LAWxA8pmylSyW5_oPkOam1PXcvA4Li4ZgoK-8DupTWI5vEm7P9B8yP9TfM0XqdZkmZZmCRRGgQefaK5H4TrMP4YRVEQhmESxcHdyaN_-qybdZZmmzTOgjDeREl6l3gUGTdSPQxbtl-2p3_O4tKt)
