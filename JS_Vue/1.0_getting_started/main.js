
const Counter = { // Step 1
	data() {
		return {
			counter: 0
		}
	},

	// Step 2 | Added Proof for DOM and Data Linked.
	mounted() {
		setInterval(() => {
			this.counter++
		}, 1000)
	}

}

const attrBind = { // Step 3
	data() {
		return {
			message: "You load this page on " + new Date().toISOString() // Changed for my preference.
		}
	}
}

const eventHandling = { // Step 4
	data() {
		return {
			message: "Hello World."
		}
	},
	methods: {
		reverseMessage() {
			// Console.debug's were extra to provide information about the string manipulation.
			console.debug(`Message on Split ${this.message.split("")}`)
			console.debug(`Message on Reverse after Split ${this.message.split("").reverse()}`)
			this.message = this.message.split("").reverse().join("")
			console.debug(`Final Output (with Join) |> ${this.message}`)
		}
	}
}

const twoWayBinding = { // Step 5
	data() {
		return {
			message: "Hello Vue!" // This is the defualt message, it will be overriden later.
		}
	}
}

const conditionalSeen  = {
	data() {
		return {
			seen_message: `You have seen this message at ${new Date().toLocaleTimeString()}`,
			seen: true // This can be dynamic if we know if it has been hit.
		}
	}
}

const listForRendering = {
	data() {
		return {
			todos: [
				{text: "Learn Javascript"},
				{text: "Learn Modern C++ (17 to 20)"},
				{text: "Learn Typescript"},
				{text: "Learn Ruby"},
				{text: "Learn Japanese"},
				{text: "Learn React"},
				{text: "and so on!!!"},

			]
		}
	}
}

Vue.createApp(Counter).mount("#counter") // Step 1
Vue.createApp(attrBind).mount('#bind-attribute') // Step 3
Vue.createApp(eventHandling).mount("#event-handling") // Step 4
Vue.createApp(twoWayBinding).mount("#two-way-binding") // Step 5
Vue.createApp(conditionalSeen).mount("#conditional-rendering") // Step 6
Vue.createApp(listForRendering).mount("#list-rendering")