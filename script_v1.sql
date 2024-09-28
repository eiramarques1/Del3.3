DROP DATABASE IF EXISTS juego;
CREATE DATABASE juego;

USE juego;

CREATE TABLE player (id INT, username VARCHAR(20), password VARCHAR(20), points INT);
CREATE TABLE game (id INT, datetime DATETIME, duration INT, winner INT);
CREATE TABLE participation (player INT, game INT);

INSERT INTO player VALUES (1, 'Juan', juan111, 10);
INSERT INTO player VALUES (2,'Maria', maria222, 20);
INSERT INTO player VALUES (3,'Pedro', pedro333, 30);
INSERT INTO player VALUES (4,'Luis', luis444, 40);
INSERT INTO player VALUES (5,'Julia', julia555, 50);

INSERT INTO game VALUES(1, '2024-01-01 10:10:00', 10, 1);
INSERT INTO game VALUES(2, '2024-02-02 20:20:00', 20, 2);
INSERT INTO game VALUES(3, '2024-03-03 03:30:00', 30, 3);

INSERT INTO participation VALUES(1,1);
INSERT INTO participation VALUES(2,1);
INSERT INTO participation VALUES(3,1);
INSERT INTO participation VALUES(4,1);
INSERT INTO participation VALUES(5,1);
INSERT INTO participation VALUES(1,2);
INSERT INTO participation VALUES(2,2);
INSERT INTO participation VALUES(3,3);
INSERT INTO participation VALUES(4,3);
INSERT INTO participation VALUES(5,3);
