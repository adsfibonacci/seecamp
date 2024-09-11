"use server";

import { promises as fs } from 'fs';
import path from 'path';

export async function readReadmeFile(c: number) {
	try {
		// Define the path to the README.md file
		const readmePath = path.join(process.cwd(), 'src/Challenge' + c + '.cpp');
		// Read the file content
		const content = await fs.readFile(readmePath, 'utf-8');
		return content;
	} catch (error) {
		console.error('Failed to read Challenge' + c + '.cpp', error);
		throw new Error('Failed to read Challenge' + c + '.cpp');
	}
}


