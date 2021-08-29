const TodoList = { // Step 1 | Create a Data
	data() {
		return {
			groceryList: [
				{ id: 0, text: "Vegetables" },
				{ id: 1, text: "Cheese" },
				{ id: 2, text: "Banana?" },
				{ id: 3, text: "Orange I guess" },
				{ id: 4, text: "Anything consumable." }
			]
		}
	}
}

f
const app = Vue.createApp(TodoList) // Step 2 | Create App as Component

// Step 3 | Create template and props that accepts parameter.
app.component("todo-item", { // Create a name for the custom tag.

	props: ["todo"], // Then create some slots for the content. For this tutorial, it may expect a list based on the given tutorial for template context.
	template: `<li>{{ todo.text }}</li>` // Remove static message `This is a todo` for dynamic content.

})

app.mount("#todo-list-app") // Step 3 | Find an ID to where we can mount this component.

// ! The section of this tutorial is incomplete. The documentation only explains some concepts.