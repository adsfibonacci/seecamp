"use server";

import { PrismaClient } from "@prisma/client";

const prisma = new PrismaClient();

export async function prismaCount1(user: string) {
	try {
		const count = await prisma.challenge1.count({
			where: {author:
					{username: user}
				   },
		})
		return count;
	}
	catch(error) {
		console.log(error);
		return 0;
	}		
}

export async function prismaCount2(user: string) {
	try {
		const count = await prisma.challenge2.count({
			where: {author:
					{username: user}
				   },
		})
		return count;
	}
	catch(error) {
		console.log(error);
		return 0;
	}		
}

export async function prismaCount3(user: string) {
	try {
		const count = await prisma.challenge3.count({
			where: {author:
					{username: user}
				   },
		})
		return count;
	}
	catch(error) {
		console.log(error);
		return 0;
	}		
}

export async function prismaCount4(user: string) {
	try {
		const count = await prisma.challenge4.count({
			where: {author:
					{username: user}
				   },
		})
		return count;
	}
	catch(error) {
		console.log(error);
		return 0;
	}		
}

export async function prismaCount5(user: string) {
	try {
		const count = await prisma.challenge5.count({
			where: {author:
					{username: user}
				   },
		})
		return count;
	}
	catch(error) {
		console.log(error);
		return 0;
	}		
}

export async function getRecent1(user: string, skips: number) {
	try {
		const submission = await prisma.challenge1.findFirst(
			{
				where: {author:
						{username: user}
					   },
				orderBy: {id: 'desc'},
				skip: skips
			}
			,);
		if(!submission) {return "No Attempts";}
		return submission.attempt;
	}
	catch(error) {
		return "Error";
	}
}

export async function getRecent2(user: string, skips: number) {
	try {
		const submission = await prisma.challenge2.findFirst(
			{
				where: {author:
						{username: user}
					   },
				orderBy: {id: 'desc'},
				skip: skips
			}
			,);
		if(!submission) {return "No Attempts";}
		return submission.attempt;
	}
	catch(error) {
		return "Error";
	}
}

export async function getRecent3(user: string, skips: number) {
	try {
		const submission = await prisma.challenge3.findFirst(
			{
				where: {author:
						{username: user}
					   },
				orderBy: {id: 'desc'},
				skip: skips
			}
			,);
		if(!submission) {return "No Attempts";}
		return submission.attempt;
	}
	catch(error) {
		return "Error";
	}
}

export async function getRecent4(user: string, skips: number) {
	try {
		const submission = await prisma.challenge4.findFirst(
			{
				where: {author:
						{username: user}
					   },
				orderBy: {id: 'desc'},
				skip: skips
			}
			,);
		if(!submission) {return "No Attempts";}
		return submission.attempt;
	}
	catch(error) {
		return "Error";
	}
}

export async function getRecent5(user: string, skips: number) {
	try {
		const submission = await prisma.challenge5.findFirst(
			{
				where: {author:
						{username: user}
					   },
				orderBy: {id: 'desc'},
				skip: skips
			}
			,);
		if(!submission) {return "No Attempts";}
		return submission.attempt;
	}
	catch(error) {
		return "Error";
	}
}
