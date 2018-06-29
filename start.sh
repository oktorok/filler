# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 23:39:39 by mrodrigu          #+#    #+#              #
#    Updated: 2018/06/29 11:03:53 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

read -e -p "Map: " map;
read -e -p "Player 1: " p1;
read -e -p "Player 2: " p2;
if [ "$map" = "" ]
then
	map="resources/maps/map01";
fi
if [ "$p1" = "" ]
then
	p1="jagarcia.filler";
fi
if [ "$p2" = "" ]
then
	p2="jagarcia.filler";
fi
while true
do
	read -e -p "Do you want music?[y/n]: " mus;
	case $mus in
		[Yy]* ) mus="afplay Mortal_Kombat.mp3"; break;;
		[Nn]* ) mus=""; break;;
		* ) echo Answer y or n;;
	esac
done
while true
do
	read -e -p "Do you want interface?[y/n]: " inter;
	case $inter in
		[Yy]* ) $mus & resources/filler_vm -f $map -p1 ./$p1 -p2 ./$p2 | ./interface; break;;
		[Nn]* ) $mus & resources/filler_vm -f $map -p1 ./$p1 -p2 ./$p2; break;;
		* ) echo Answer y or n;;
	esac
done
if [ "$mus" != "" ]
then
	killall afplay
fi
