/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:14 by ageiser           #+#    #+#             */
/*   Updated: 2023/09/14 21:39:02 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_free(char *buffer, char *buffer2)
{
	char	*temp;

	temp = ft_strjoin(buffer, buffer2);
	free(buffer);
	return (temp);
}
//fonction qui a la fois assemble les deux buffers et libere le buffer

char	*ft_next(char *buffer)
{
	int		i ;
	int		j;
	char	*next_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) -i + 1));
	if (!next_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
	next_buffer[j++] = buffer[i++];
	next_buffer[j] = '\0';
	free(buffer);
	return (next_buffer);
}
//fonction qui permet de decaler le buffer sur 
//la ligne suivante ou si on prefere,
//qui supprime la ligne precedente et ne garde que le reste
//ligne 32 compteur de premiere ligne du buffer
//ligne 34 gestion d'erreur
//ligne 39 creation du malloc du reste du buffer
//ligne 42 on ajoute 1 a i pour le saut de ligne
//ligne 45 tant qu'on est dans le buffer sans la ligne de 
//depart et le saut de ligne, on le copie dans next_buffer
//ligne 46 on ajoute la fin de chaine

char	*ft_line_isolator(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
	line[i] = buffer[i];
	i++;
	}
	if (buffer[i] == '\n')
	{
	line[i] = buffer[i];
	i++;
	}
	line[i] = '\0';
	return (line);
}
//fonction qui isole la ligne
//ligne 63 creation du pointeur de sortie
//ligne 67 gestion d'erreur
//ligne 69 compteur du nombre de caracteres jusqu'au
//retour a la ligne
//ligne 71 creation du malloc pour la ligne, + 2 parce qu'on
//rajoute le retour a la ligne et la fin de chaine
//ligne 80 rajour du retour a la ligne
//ligne 85 rajout de la fin de chaine

char	*ft_file_reader(int fd, char *buffer)
{
	char	*buffer2;
	int		byte_read;

	buffer2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer2)
		return (NULL);
	buffer2[0] = '\0';
	byte_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	while (byte_read != 0 && !ft_strchr(buffer, '\n'))
	{
		byte_read = read(fd, buffer2, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer2);
			return (NULL);
		}
	buffer2[byte_read] = '\0';
	buffer = ft_join_free(buffer, buffer2);
	}
	free(buffer2);
	return (buffer);
}
//ligne 98 fonction qui lit le fichier et met dans le tampon le texte
//linge 100 creation d'un deuxieme tampon
//ligne 101 compteur de byte lu
//ligne 103 on cree un malloc qui fait la taille de BUFFER_SIZE + 1
//linge 104 gestion d'erreur du malloc de buffer2
//ligne 106 on initalise le buffer 2 qui ne peut etre vide
//ligne 108 gestion d'erreur si il n'a a pas de buf de depart
//linge 109 dans ce cas on cree un malloc d'un espace qu'on
//initialise a zero pour pouvoir le retourner
//ligne 110 tant que le byte_read est differnt de zero et qu-on a 
//pas trouve le retour a la ligne dans le tampon
//ligne 112 read retourne le nombre de byte lu, 0 si eof et
//-1 en cas d'erreur, 
//ligne 113 si le retour de read == - 1, gestion d'erreur
//ligne 118 on ajoute la fin de chaine
//ligne 119 buffer qui jusqu'a present est vide recoit l'assemblage  
//de buffer et buffer2
//ligne 121 on libere buffer2
//ligne 122 on retourne buffer qui, maintenant, contient
//le texte jusqu'a BUFFERSIZE

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}	
		return (NULL);
	}
			buffer = ft_file_reader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line_isolator(buffer);
	buffer = ft_next(buffer);
	return (line);
}

//ligne 148 pointeur qui retournera la ligne
//ligne 155 si on a rempli le buffer avec qqch mais que le reste n'a 
//pas fonctionne on free le buffer
//ligne 156 et on reinitialise le buffer
//ligne 160 on met dans buffer le texte qui sera de longueur donnee par 
//BUFFER_SIZE dans la compilation
//linge 161 gestion des erreurs si file_reader n'a pas fonctionne

//BUFFER_SIZE = valeur donnee par l'utilisateur
//ssize_t read(int filde, void *buf, size_t nbytes)

//ligne 163 ecriture que la premiere ligne depuis le buffer
//ligne 164 decalage du buffer sur la ligne suivante
