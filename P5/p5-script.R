library(tuneR)
library(seewave)
library(audio)
setwd("~/pdih-temp/entrega")


#Ejercicio 1
perro <- readWave('perro.wav')
oveja <- readWave('oveja.wav')
#listen(perro)
#listen(oveja)

#Ejercicio 2
plot(perro)
plot(oveja)

#Ejercicio 4
oveja44100 <- resamp(oveja, f=8000, g=44100, output="Wave")
nuevo <- pastew(perro, oveja44100, output="Wave")
#listen(nuevo)

#Ejercicio 5
plot(nuevo)

#Ejercicio 6
mezcla <- bwfilter(nuevo, channel=1, n=1, from=10000,
         to=20000, bandpass=TRUE, listen = FALSE, output = "Wave")
#listen(mezcla)

#Ejercicio 7
writeWave(mezcla, file.path("output/mezcla.wav"), extensible = TRUE)

#Ejercicio 8
guitar <- readWave('guitar.wav')
guitarCUT <- cutw(guitar, from=0.0,to=2.0, output="Wave")
guitarECO <- echo(guitarCUT,amp=c(0.8,0.4,0.2),delay=c(1,2,3), output="Wave")
guitarECO@left <- 10000 * guitarECO@left
alreves <- revw(guitarECO, output="Wave")
plot(alreves)
#listen(alreves)
writeWave(alreves, file.path("output/alreves.wav"), extensible = TRUE)




