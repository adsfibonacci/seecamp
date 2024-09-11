"use server";

import { PrismaClient } from '@prisma/client';

const prisma = new PrismaClient();

export async function login(user: string, pass: string) {
	console.log(user);
	if(!user || !pass) return {status: false, message: 1}; 

	try {
		const userDB = await prisma.user.findUnique({where: {username: user}});
		if(!userDB) return {status: false, message: 2}; 
		if(pass != userDB.password) return {status: false, message: 3}; 
		return {status: true, message: 0}; 
	}
	catch(error) {
		console.log("Start Error");
		console.log(error);
		console.log({user, pass});
	}
	finally {
		await prisma.$disconnect();
	}
	return {status: false, message: -1} //-1 Undefined
}
