declare module 'constrained-editor-plugin' {
    export function constrainedEditor(monaco: any): {
        initializeIn(editor: any): void;
        addRestrictionsTo(model: any, restrictions: Array<{
            range: [number, number, number, number];
            label: string;
            allowMultiline?: boolean;
            validate?: (currentlyTypedValue: string, newRange: any, info: any) => boolean;
        }>): void;
    };
}
