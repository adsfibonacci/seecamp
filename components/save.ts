"use server";

import { PrismaClient } from '@prisma/client';

import { promises as fs } from 'fs';
import path from 'path';

const prisma = new PrismaClient();

export async function saveToFile(user: string, challenge: number, content: string | undefined) {// (editorRef: React.MutableRefObject<editor.IStandaloneCodeEditor | null>) {
	if (!content) return;
	const fileName = user + 'SavedContent.cpp'; // Example file name
	if (content) {
		try {
			const filePath = path.join(process.cwd(), 'savedFiles', fileName);
			await fs.mkdir(path.dirname(filePath), { recursive: true });
			await fs.writeFile(filePath, content, 'utf8');
		}
		catch (error) {
			alert('failed save');
			console.error('Error saving file:', error);
		}

		try {
			const userDB = await prisma.user.findUnique({where: {username: user}});
			if(!userDB) {throw new Error("wtf");}

			//chal = {};

			if(challenge == 1) {
				const chal = await prisma.challenge1.create({
						data: {
							authorId: userDB.id,
							attempt: content,
						},
				});
				return chal;
			}
			if(challenge == 2) {
				const chal = await prisma.challenge2.create({
						data: {
							authorId: userDB.id,
							attempt: content,
						},
				});
				return chal;
			}
			if(challenge == 3) {
				const chal = await prisma.challenge3.create({
						data: {
							authorId: userDB.id,
							attempt: content,
						},
				});
				return chal;
			}
			if(challenge == 4) {
				const chal = await prisma.challenge4.create({
						data: {
							authorId: userDB.id,
							attempt: content,
						},
				});
				return chal;
			}
			if(challenge == 5) {
				const chal = await prisma.challenge5.create({
						data: {
							authorId: userDB.id,
							attempt: content,
						},
				});
				return chal;
			}
		}
		catch(error) {
			console.error(error);
		}
	}
};
