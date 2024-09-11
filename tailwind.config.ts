import { nextui } from '@nextui-org/theme';
import type { Config } from "tailwindcss";

const config: Config = {
	content: [
		"./pages/**/*.{js,ts,jsx,tsx,mdx}",
		"./components/**/*.{js,ts,jsx,tsx,mdx}",
		"./app/**/*.{js,ts,jsx,tsx,mdx}",
		"./node_modules/@nextui-org/theme/dist/components/(button|input|ripple|spinner).js"
	],
	theme: {
		extend: {
			maxHeight: {
				'50p': '50%', // 50% height
				'60p': '60%', // 60% height
				'70p': '70%', // 70% height
				'80p': '80%', // 80% height
				'90p': '90%', // 90% height
				'100p': '100%',
			},
			width: {
				'1/8': '12.5%',
				'3/8': '37.5%',
				'5/8': '62.5%',
				'7/8': '87.5%'
			},
			height: {
				'1/8': '12.5%',
				'3/8': '37.5%',
				'5/8': '62.5%',
				'7/8': '87.5%',
				'1/10': '10%',
				'9/10': '90%',
			},
			backgroundImage: {
				"gradient-radial": "radial-gradient(var(--tw-gradient-stops))",
				"gradient-conic":
					"conic-gradient(from 180deg at 50% 50%, var(--tw-gradient-stops))",
			},
		},
	},
	plugins: [nextui()],
};
export default config;
