"use client";

import React, { useEffect, useRef, useState } from 'react';
import Editor from '@monaco-editor/react';
import { editor } from 'monaco-editor';
import { Button } from '@nextui-org/button';
import { useRouter } from 'next/navigation';
import Cookies from 'js-cookie';

import { readReadmeFile } from '@/components/fileaction';
import { handleEditorDidMount } from '@/components/monaco-constraints';
import { saveToFile } from '@/components/save';
import { getRecent2, prismaCount2 } from '@/components/getrecentchallenge';

export default function Home() {

	const [message, setMessage] = useState('');
	const [skips, setSkips] = useState(0);

	const router = useRouter();
	if (!Cookies.get('username')) router.push('/');
	const username = Cookies.get('username')!;

	const [editorContent, setEditorContent] = useState<string>(
		"First line\nSecond line\nThird line\nFourth line\nFifth line"
	);
	const editorRef = useRef<editor.IStandaloneCodeEditor | null>(null);
	const lines: Array<{ range: [number, number, number, number], label: string }> = [
		{ range: [30, 1, 33, 1], label: 'editableSection' }
	];

	useEffect(() => {
		(async () => {
			try {
				const content = await readReadmeFile(2);
				setEditorContent(content);
			} catch (error) {
				console.error('Error fetching Challenge1.cpp:', error);
				setEditorContent('Error loading Challenge1.cpp');
			}
		})();
	}, []);

	return (
		<div className="h-screen flex flex-row">
			<div className="w-3/5 h-full">
				<Editor
					height="90%"
					theme="vs-dark"
					language="cpp"
					value={editorContent}
					onMount={(editor, monaco) => {
						try {
							handleEditorDidMount(editor, monaco, editorRef, lines);
						}
						catch (error) {
							console.log("Refreshing Monaco Editor");
							router.push('challenge2');
						}
					}} />
				<Button color="warning"
					style={{ marginTop: '10px' }}
					onClick={async () => {
						if (!editorRef.current) return;
						saveToFile(username, 2, editorRef.current?.getModel()?.getValue());
						const temp = await getRecent2(username, 0);
						setMessage(temp);
						setSkips(0);
					}}>Submit</Button>
			</div >

			<div className="w-2/5 h-full">
				<div className="w-full h-7/8">
					<div className="bg-gray-800 p-4 rounded-lg mb-2 shadow h-full">
						<pre className="whitespace-pre-wrap max-h-90p overflow-auto text-base">
							<code>{message}</code>
						</pre>
					</div>
				</div>
				<div className="w-full h-1/8">
					<Button color="success" onClick={async () => {
						const size = await prismaCount2(username);
						const newSkips = skips + 1;
						setSkips(newSkips % size);
						const mes = await getRecent2(username, skips);
						setMessage(mes);
					}}>&lt;&lt;</Button>
					{skips}
					<Button color="success" onClick={async () => {
						const size = await prismaCount2(username);
						const newSkips = skips - 1;
						setSkips((newSkips + size) % size);
						const mes = await getRecent2(username, skips);
						setMessage(mes);
					}}>&gt;&gt;</Button>
				</div>
			</div>

		</div>
	);
}
