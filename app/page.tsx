"use client";

import { useState } from 'react';
import { Button } from '@nextui-org/button';
import { Input } from '@nextui-org/input';
import { useRouter } from 'next/navigation';
import Cookies from 'js-cookie';

import { login } from '@/components/auth';

export default function LoginPage() {
	const [username, setUsername] = useState('');
	const [password, setPassword] = useState('');
	const [inputs, setInputs] = useState('');
	const [users, setUsers] = useState('');
	const [passs, setPasss] = useState('');
	const router = useRouter();

	const clicker = async () => {
		const { status, message } = await login(username, password);
		if (status) {
			Cookies.set('username', username, { expires: 1 });
			router.push('challenge1');
		}
		else {
			if (message == 1) {
				setInputs("Fields Cannot Be Blank");
				setUsers('');
				setPasss('');
			}
			if (message == 2) {
				setInputs('');
				setUsers("Incorrect Username");
				setPasss('');
			}
			if (message == 3) {
				setInputs('');
				setUsers('');
				setPasss("Incorrect Password");
			}
		}
	}

	return (
		<div>
			<div>
				<label htmlFor="username">Username</label>
				<Input
					id="username"
					name="username"
					placeholder="Username"
					value={username}
					onChange={(e) => setUsername(e.target.value)}
				></Input>
				<p>{users}</p>
			</div>
			<div>
				<label htmlFor="password">Password</label>
				<Input
					id="password"
					name="password"
					type="password"
					placeholder="Password"
					value={password}
					onChange={(e) => setPassword(e.target.value)}
				></Input>
				<p>{passs}</p>
			</div>
			<p>{inputs}</p>
			<Button
				color="warning"
				onClick={clicker}
			>Login</Button>
		</div>
	);
}
