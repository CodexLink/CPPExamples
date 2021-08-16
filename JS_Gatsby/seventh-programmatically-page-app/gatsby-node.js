// ! We create backends to handle the markdowns.

// * The Node Internal Type Console Log Shows All Files correlated to this web-app.
// - Usually this will be used to determine which files to be processed later.
// ! For each file, is defined as node, here in this case.

// - FIRST ATTEMPT | DEPRECATED DUE TO EXCESSED INFORMATION.
// ! The IF statement shows effects in the end of the file. Please see that.
// @o — We let node and getNode as our parameter from this function. Gatsby will ensure to supply the following args.
// exports.onCreateNode = ({ node, getNode }) => {
//     if (node.internal.type === `MarkdownRemark`) { // ! Node Internal Type is File Type. Queryable in GraphiQL.
//         //console.log(node); // ! Outputs File Contents
//         //console.log(getNode); // ! Outputs as Function Declaration. [function: getNode]
//         //console.log(node.parent); // ! Outputs Node ID. ID is their parent.
//         //console.log(getNode(node.parent)); // ! Outputs Node Properties. Which is Nodes SubTree.
//         //console.log(node.internal.type); // ! Outputs Node (as file) type.
//         const fileNode = getNode(node.parent); // - Const FileNode Gets That Subtree from That Particular Nodes.
//         // console.log(fileNode); // * Check the output of fileNode here just in case if you really want to know.
//         //console.log('\n', fileNode.relativePath); // ! \n is optional. Outputs fileNode filename with extension along with the path.
//     }
// }

// ! Import in CommonJS since we're in NodeJS Environment.
// @o — The objective here was to create a slug.
// - To automate, we have to use gatsby-source-filesystem. Since automation on creating slugs has it already. (func)

const { createFilePath } = require(`gatsby-source-filesystem`);
const path = require('path');

// ! We have a file for instance, and we want to convert it to a URL accessible page.
// @output — pages/hello.md => /hello/
exports.onCreateNode = ({ node, getNode, actions }) => {
    if (node.internal.type === `MarkdownRemark`) {

        const { createNodeField } = actions; // ! We get possible actions from var actions, then choose createNodeField.

        // ! To understand further, know the following args
        //  - node | Literally the nodes.
        //  - getNode | Get base path for those nodes, which is files.
        //  - basePath: A supplied string will be concatenated to suffix of the URL.
        // ! For instance, let basePath be `pages`, then, /pages/hello/
        //console.log(createFilePath({ node, getNode, basePath: `pages` }));

        // ! ACCESSIBILITY IMPLEMENTATION
        // - We have to put that output somewhere, so we have to put it into variable named slug.
        const slug = createFilePath({ node, getNode, basePath: `pages` });

        // - We create a custom field to be accessed by GraphiQL.
        createNodeField({
            node, // * The target is markdown.
            name: `slug`, // ! The name of the field.
            value: slug, // * The value of the slug field.
        }); // TODO: (By you.) | After restarting your development server, you should now query the slug of allMarkdownNodes.edges.node.fields.slug.
    } // @promise - By this point, we're in 50% implementation at connecting our markdown file with the links in the web-app :). At this point, we have to do createPages.

}; // ! When attempting to restart the server, you were still unable to access those URL Slugs, you have to implement it.

// ! The output of this one is similary to GraphQL if you try to query `allMarkdownNodes.edges.node.fields.slug`.
exports.createPages = async ({ graphql, actions }) => {
    // **Note:** The graphql function call returns a Promise
    // see: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise for more info

    const { createPage } = actions;

    // ! Await states to wait further until the query is resolved.
    const result = await graphql(`
      query {
        allMarkdownRemark {
          edges {
            node {
              fields {
                slug
              }
            }
          }
        }
      }
    `);
    // #                         [1]data, [2]transformer, [3]space indention level.
    //console.log(JSON.stringify(result, null, 4)); // * Reconstruct Output Proper.

    // ! PROCESS ALL PAGES INTO ACCESSIBLE ONE.
    // - For each Nodes that is a markdown... Create a page for it.
    result.data.allMarkdownRemark.edges.forEach(({ node }) => {
        createPage({
            path: node.fields.slug, // ! Create those nodes with the path of the following. (The path are the things that we did recently on the top!!!)
            component: path.resolve(`./src/templates/blog-post.js`), // ! Resolve those paths to this particular renderer JS.
            context: { // ! Context Given To Resolver.
                // Data passed to context is available
                // in page queries as GraphQL variables.
                slug: node.fields.slug,
            },
        });
    });

};




// ! If Statement Within Console Log Scope — Enabled
// * success initialize cache - 0.062s
// * success copy gatsby files - 0.247s
// * success onPreBootstrap - 0.018s
// * success createSchemaCustomization - 0.011s
// - MarkdownRemark
// - MarkdownRemark

// ! If Statement Within Console Log Scope — Disabled
// * success initialize cache - 0.062s
// * success copy gatsby files - 0.247s
// * success onPreBootstrap - 0.018s
// * success createSchemaCustomization - 0.011s
// - SitePage
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - SitePlugin
// - Site
// - SiteBuildMetadata
// - Directory
// - Directory
// - Directory
// - Directory
// - File
// - File
// - File
// - File
// - File
// - File
// - File
// - File
// - MarkdownRemark
// - MarkdownRemark
// ! success source and transform nodes - 0.587s
// ! success building schema - 0.262s
// ! success createPages - 0.005s