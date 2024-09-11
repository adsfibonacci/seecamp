//import from 'react';
import { editor } from 'monaco-editor';
import { Monaco } from '@monaco-editor/react';

import { constrainedEditor } from 'constrained-editor-plugin';

function initializeConstrainedEditor(editor: editor.IStandaloneCodeEditor,
									 monaco: Monaco,
									 ranges: Array<{range: [number, number, number, number], label: string}>) {
	if (monaco && editor) {
		const model = editor.getModel();
		if (model) {
			console.log("Creating constrained editor instance");
			const constrainedInstance = constrainedEditor(monaco);
			constrainedInstance.initializeIn(editor);
			constrainedInstance.addRestrictionsTo(model, ranges);
			console.log("Constraints have been applied successfully");
		} else {
			console.error("Model not found");
		}
	} else {
		console.error("Monaco or editor instance not found");
	}
};

export function handleEditorDidMount(editor: editor.IStandaloneCodeEditor,
									 monaco: Monaco,
									 editorRef: React.MutableRefObject<editor.IStandaloneCodeEditor | null>,
									 ranges: Array<{range: [number, number, number, number], label: string}>) {
	editorRef.current = editor;
	initializeConstrainedEditor(editor, monaco, ranges);
};
